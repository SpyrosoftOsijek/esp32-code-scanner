#include "include/opencv/modules/objdetect/include/opencv2/objdetect/barcode.hpp"
#include "include/barcode_reader.hpp"
#include <stdio.h>
#include <mat.hpp>


std::vector<std::string> BarcodeDetectionComponent::detect(cv::InputArray image)
{
    cv::barcode::BarcodeDetector detector;
    std::vector<std::string> decoded_info;
    std::vector<std::string> decoded_type;

    detector.detectAndDecodeWithType(image, decoded_info, decoded_type);
    return decoded_info;
}
