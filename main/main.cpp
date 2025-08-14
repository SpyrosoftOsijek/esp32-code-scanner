/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

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
            vTaskDelay(pdMS_TO_TICKS(400));
        }
    }
    catch (const CameraInitException &e)
    {
        ESP_LOGE("MAIN", "Fatal error during camera setup: %s", e.what());

        abort(); // kills app
    }
}