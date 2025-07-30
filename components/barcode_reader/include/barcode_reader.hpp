#pragma once

//#include "opencv2/objdetect/barcode.hpp"
//#include "opencv2/gapi/own/mat.hpp"
#include <stdio.h>

class BarcodeReader {

    public:
        int read(int image);
        //std::vector<cv::String> read(InputArray image);

};
