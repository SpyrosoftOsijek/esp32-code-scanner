
#include "cam.hpp"
#include "esp_log.h"
#include "unity.h"
#include "esp_camera.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// static const char* TAG = "CAMERA_TEST"; // limits variable scope to this file 

TEST_CASE("Camera capture returns framebuffer", "[cam]"){
    camera_config_t config = get_default_camera_config();
    Camera cam(config);
    
    camera_fb_t* fb = cam.capture();
    TEST_ASSERT_NOT_NULL(fb);

    cam.release(fb);
}
