#include <string>
#include "Barcode.h"
#include "raw_img.hpp"

class BarcodeReader {

    public:
        ZXing::Barcodes read(std::shared_ptr<rawImg> img);

};