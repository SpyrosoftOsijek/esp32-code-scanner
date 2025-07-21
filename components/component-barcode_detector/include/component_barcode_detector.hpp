#include <stdio.h>
#include <mat.hpp>


class BarcodeDetectionComponent {

    public:
        std::vector<std::string> detect(cv::InputArray image);

};
