#pragma once

#include <stdio.h>
#include <string>

class BarcodeReader {

    public:
        std::string read(const uint8_t raw_image[2][154]);

};