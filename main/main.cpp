/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "wifi_post_component.hpp"
#include "freertos/task.h"
#include <inttypes.h>
#include "freertos/task.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "esp_camera.h"
#include "cam.hpp"
#include "esp_log.h"
#include "raw_img.hpp"
#include "barcode_reader.hpp"
#include <string>



extern "C" void app_main()
{

    try
    {
        esp_err_t status = WIFI_FAILURE;

        // init storage
        esp_err_t ret = nvs_flash_init();
        if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
        {
          ESP_ERROR_CHECK(nvs_flash_erase());
          ret = nvs_flash_init();
        }
        ESP_ERROR_CHECK(ret);

        // connect to wireless AP
        status = connect_wifi();
        if (WIFI_SUCCESS != status)
        {
          ESP_LOGI("WIFI", "Failed to associate to AP, dying...");
          return;
        }

        const char *test_barcode = "12345";


        Camera cam{};
        BarcodeReader reader;
        while (true)
        {
            try
            {
                auto image = cam.capture();

                std::string result = reader.read(image);
                std::cout << "Loop" << result << std::endl;
            }
            catch (const CameraCaptureException &e)
            {
                ESP_LOGE("MAIN", "Capture failed: %s", e.what());
                abort();
            }
            send_barcode_post(test_barcode);
            vTaskDelay(pdMS_TO_TICKS(400));
        }
    }
    catch (const CameraInitException &e)
    {
        ESP_LOGE("MAIN", "Fatal error during camera setup: %s", e.what());

        abort(); // kills app
    }
}