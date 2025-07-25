
#include "cam.hpp"
#include "esp_log.h"
#include "unity.h"
#include "esp_camera.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


// WE TO INSTANTIATE A STATIC CAM DUE TO TEST RUNNING FAST 
// IF CAM IN METHOD -> NO TIME TO DEINIT

static const char* TAG = "CAMERA_TEST";
static Camera cam;

extern "C" void setUp(void) {
    esp_camera_deinit();
    vTaskDelay(100 / portTICK_PERIOD_MS);
}

extern "C" void tearDown(void) {
    esp_camera_deinit();
    vTaskDelay(100 / portTICK_PERIOD_MS);
}

TEST_CASE("Camera init returns true", "[cam]"){
    bool ok = cam.init();
    ESP_LOGI(TAG, "Camera init returned: %d", ok);
    TEST_ASSERT_TRUE_MESSAGE(ok, "cam init failed");
}

TEST_CASE("Camera capture returns framebuffer", "[cam]"){
    TEST_ASSERT_TRUE(cam.init());

    void* fb = cam.capture();
    TEST_ASSERT_NOT_NULL(fb);

    cam.release(fb);
}
