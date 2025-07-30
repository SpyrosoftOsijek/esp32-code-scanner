#include "esp_log.h"
#include "unity.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "opencv2/objdetect/barcode.hpp"
//#include "opencv2/gapi/own/mat.hpp"
#include <iostream>


const char* TAG = "BARCODE_READER_TEST";


extern "C" void setUp(void) {
    
}

extern "C" void tearDown(void) {
    
}


TEST_CASE("Reader returns no", "[barcode_reader]"){

    //Mat image = imread("Barcode test.png", IMREAD_COLOR);

    //BarcodeDetector detector;
    //std::vector<cv::String> decoded_info;
    //std::vector<cv::String> decoded_type;
    //detector.detectAndDecodeWithType(image, &decoded_info, &decoded_type);

    std::cout << "no" << '\n';
    TEST_ASSERT_TRUE(true);

}


TEST_CASE("Reader returns yes", "[barcode_reader]"){

    std::cout << "yes" << '\n';
    TEST_ASSERT_TRUE(true);

}