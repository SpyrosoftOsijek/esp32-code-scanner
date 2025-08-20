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
    BarcodeReader reader;
    std::shared_ptr<rawImg> image = {};
    ZXing::Barcodes results = reader.read(image);
    std::cout << "Loop";
    for(ZXing::Barcode result : results) std::cout << " " << result.text();
    std::cout << std::endl;
}

