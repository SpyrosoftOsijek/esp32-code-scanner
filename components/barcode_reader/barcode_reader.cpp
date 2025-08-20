#include "barcode_reader.hpp"
#include "ReadBarcode.h"
#include "Barcode.h"
#include <string>
#include "raw_img.hpp"


 
ZXing::Barcodes BarcodeReader::read(std::shared_ptr<rawImg> img)
{  
    ZXing::ImageView iv(reinterpret_cast<uint8_t*>(&img->image), img->width(), img->height(), ZXing::ImageFormat::Lum, img->width());
    auto options = ZXing::ReaderOptions().setFormats(ZXing::BarcodeFormat::Any);
    auto results = ZXing::ReadBarcodes(iv, options);
    return results;
}