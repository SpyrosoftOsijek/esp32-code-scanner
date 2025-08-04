
#include "cam.hpp"
#include "esp_log.h"
#include "unity.h"
#include "esp_camera.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "raw_img.hpp"


// static const char* TAG = "CAMERA_TEST"; // limits variable scope to this file 

TEST_CASE("Camera capture returns framebuffer", "[cam]"){
    Camera cam{};


    std::shared_ptr<rawImg> img = cam.capture();
    TEST_ASSERT_NOT_NULL(img.get());

    

    TEST_ASSERT_EQUAL_UINT8(IMG_HEIGHT, img->imgHeight());
}
