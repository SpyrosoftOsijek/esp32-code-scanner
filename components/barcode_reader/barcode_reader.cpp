#include "include/barcode_reader.hpp"
#include "ReadBarcode.h"
#include "Barcode.h"
#include <iostream>
#include <stdio.h>
#include <string>

#include "raw_img.hpp"


 
std::string BarcodeReader::read(std::shared_ptr<rawImg> img)
{
    ZXing::ImageView iv(reinterpret_cast<uint8_t*>(&img->image), IMG_WIDTH, IMG_HEIGHT, ZXing::ImageFormat::Lum, IMG_WIDTH);


    auto options = ZXing::ReaderOptions().setFormats(ZXing::BarcodeFormat::Any);
    auto results = ZXing::ReadBarcodes(iv, options);

    if (!results.empty()) {
        return results[0].text();
    }
    return {};
}