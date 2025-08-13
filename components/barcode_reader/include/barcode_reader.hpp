#pragma once

#include <stdio.h>
#include <string>
#include "raw_img.hpp"

class BarcodeReader {

    public:
        std::string read(std::shared_ptr<rawImg> img);

};