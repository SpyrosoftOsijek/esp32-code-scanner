#pragma once // same as ifndef endif

#include <iostream>
#include <memory>
#include "esp_camera.h"
#include "raw_img.hpp"

// Camera init exception type
class CameraInitException : public std::exception {
    public: 
    explicit CameraInitException(const char* message) : msg_(message) {}
    
    const char* what() const noexcept override {
        return msg_;
    }

    private: 
    const char* msg_;
};

class CameraCaptureException : public std::exception {
    public: 
    explicit CameraCaptureException(const char* message) : msg_(message) {}
    
    const char* what() const noexcept override {
        return msg_;
    }

    private: 
    const char* msg_;
};

static constexpr camera_config_t DEFAULT_CAMERA_CONFIG
{
    .pin_pwdn = -1,
    .pin_reset = -1,
    .pin_xclk = 15,
    .pin_sccb_sda = 4,
    .pin_sccb_scl = 5,
    .pin_d7 = 16,
    .pin_d6 = 17,
    .pin_d5 = 18,
    .pin_d4 = 12,
    .pin_d3 = 10,
    .pin_d2 = 8,
    .pin_d1 = 9,
    .pin_d0 = 11,
    .pin_vsync = 6,
    .pin_href = 7,
    .pin_pclk = 13,
    .xclk_freq_hz = 10000000,
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,
    .pixel_format = PIXFORMAT_GRAYSCALE, // fixed DMA overflow -> cam needed more space so PSRAM Was enabled in menuconfig
    .frame_size = FRAMESIZE_QVGA,
    .jpeg_quality = 12,
    .fb_count = 1,
    .fb_location = CAMERA_FB_IN_PSRAM,
    .grab_mode = CAMERA_GRAB_WHEN_EMPTY,
    .sccb_i2c_port = 1,
};

class Camera {
    public:
        Camera(camera_config_t config);

        Camera();
        
        ~Camera();
        
        Camera(Camera& obj) = delete;

        Camera& operator=(Camera& obj) = delete;

        std::shared_ptr<rawImg> capture();
        
    private:
        camera_config_t _config;
        std::shared_ptr<rawImg> img_ = {std::make_unique<rawImg>()};
};