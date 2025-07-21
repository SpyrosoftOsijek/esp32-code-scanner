#include "camera_component.hpp"
#include "esp_log.h"


static const char* TAG = "OV5640";

bool Camera::init() {
    camera_config_t config;

    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;

    config.pin_d0 = GPIO_NUM_10; //d2red
    config.pin_d1 = GPIO_NUM_38; //d3ora
    config.pin_d2 = GPIO_NUM_39; //d4 yell
    config.pin_d3 = GPIO_NUM_21; // d5 green
    config.pin_d4 = GPIO_NUM_12; // d6 blue
    config.pin_d5 = GPIO_NUM_13; // d7brown
    config.pin_d6 = GPIO_NUM_14; //  d8 green 
    config.pin_d7 = GPIO_NUM_42; // d9 red 

    //config.pin_xclk = 
    config.pin_pclk = 19;
    config.pin_vsync = GPIO_NUM_11;
    config.pin_href = GPIO_NUM_9;

    config.pin_sccb_sda = GPIO_NUM_41;
    config.pin_sccb_scl = GPIO_NUM_40;

    config.pin_pwdn = -1;
    config.pin_reset = -1;

    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;

    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        ESP_LOGE("CAMERA", "Camera init failed: 0x%x", err);
        return false;
    }

    ESP_LOGI("CAMERA", "Camera initialized successfully");
    return true;
}


camera_fb_t* Camera::capture() {
    return esp_camera_fb_get();
}

void Camera::release(camera_fb_t* fb) {
    esp_camera_fb_return(fb);
}
