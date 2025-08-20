/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "raw_img.hpp"
#include "barcode_reader.hpp"
#include "Barcode.h"
#include <iostream>
#include <string>

extern "C" void app_main()
{
    try
    {

        Camera cam{};

        while (true)
        {
            try
            {
                auto image = cam.capture();
                BarcodeReader reader;
                ZXing::Barcodes results = reader.read(image);
                std::cout << "Loop";
                for(ZXing::Barcode result : results) std::cout << " " << result.text();
                std::cout << std::endl;
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
