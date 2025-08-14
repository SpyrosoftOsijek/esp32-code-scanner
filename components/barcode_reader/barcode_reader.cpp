#include "include/barcode_reader.hpp"
#include "core/src/ReadBarcode.h"
#include "core/src/Barcode.h"
#include <iostream>
#include <stdio.h>
#include <string>

#define width 154
#define height 2


std::string BarcodeReader::read(const uint8_t raw_image[2][154])
{
    auto image = ZXing::ImageView((const uint8_t*)raw_image, width, height, ZXing::ImageFormat::Lum, 0, 0);
    auto options = ZXing::ReaderOptions().setFormats(ZXing::BarcodeFormat::Any);
    auto barcode = ZXing::ReadBarcode(image, options);
    return barcode.text();
}