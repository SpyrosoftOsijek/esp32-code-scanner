#include "esp_camera.h"
#include "esp_log.h"
#include "cam.hpp"
#include "esp_mac.h"


bool Camera::init() {
    camera_config_t config;

    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer   = LEDC_TIMER_0;

    config.pin_d0       = 11;
    config.pin_d1       = 9;
    config.pin_d2       = 8;
    config.pin_d3       = 10;
    config.pin_d4       = 12;
    config.pin_d5       = 18;
    config.pin_d6       = 17;
    config.pin_d7       = 16;

    config.pin_xclk     = 15;
    config.pin_pclk     = 13;
    config.pin_vsync    = 6;
    config.pin_href     = 7;

    config.pin_sccb_sda = 4;
    config.pin_sccb_scl = 5;

    config.pin_pwdn     = -1;
    config.pin_reset    = -1;

    config.xclk_freq_hz = 10000000;
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


void* Camera::capture() {
    return esp_camera_fb_get();
}

void Camera::release(void* fb) {
    esp_camera_fb_return((camera_fb_t*)fb);
}
