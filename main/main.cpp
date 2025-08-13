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

    const uint8_t data[2][154] = {{  0,  0,  0,  0, 255, 255,  0,  0, 255, 255, 255, 255, 255, 255, 255, 255,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255, 255, 255,  0,  0,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0,  0,  0, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255,  0,  0, 255, 255, 255, 255, 255, 255, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255,  0,  0, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255, 255, 255, 255, 255, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255, 255, 255,  0,  0,  0,  0,  0,  0, 255, 255,  0,  0, 255, 255,  0,  0,  0,  0},
                                  {  0,  0,  0,  0, 255, 255,  0,  0, 255, 255, 255, 255, 255, 255, 255, 255,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255, 255, 255,  0,  0,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0,  0,  0, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255,  0,  0, 255, 255, 255, 255, 255, 255, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255,  0,  0, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255,  0,  0, 255, 255, 255, 255, 255, 255, 255, 255,  0,  0,  0,  0, 255, 255, 255, 255, 255, 255,  0,  0,  0,  0,  0,  0, 255, 255,  0,  0, 255, 255,  0,  0,  0,  0}};
    
    BarcodeReader reader;
    std::string result = reader.read(data);
    std::cout << result << '\n';

    std::cout << "TESTTESTTESTTESTTESTTESTTESTTEST\n";
    std::cout << result << '\n';
    std::cout << "TESTTESTTESTTESTTESTTESTTESTTEST\n";

    try
    {

        Camera cam{};

        while (true)
        {

            try
            {
                auto image = cam.capture();
            }
            catch (const CameraCaptureException &e)
            {
                ESP_LOGE("MAIN", "Capture failed: %s", e.what());
                abort();
            }
            vTaskDelay(pdMS_TO_TICKS(4000));
            
        }
    }
    catch (const CameraInitException &e)
    {
        ESP_LOGE("MAIN", "Fatal error during camera setup: %s", e.what());

        abort(); // kills app
    }
}
