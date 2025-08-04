#include "esp_log.h"
#include "cam.hpp"
#include "esp_mac.h"




Camera::Camera(camera_config_t config) : _config(config) //initializer list 
{
    esp_err_t err = esp_camera_init(&_config);
    if (err != ESP_OK) {
        throw CameraInitException("Camera init failed!"); 
    }
    ESP_LOGI("CAMERA", "Camera initialized successfully");
}

Camera::Camera() : Camera::Camera(DEFAULT_CAMERA_CONFIG)
{
}

Camera::~Camera()
{
    esp_camera_deinit();
}

std::shared_ptr<rawImg> Camera::capture()
{ // void gave no info about whats inside pointer
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
        throw std::runtime_error("Failed to get frame buffer");
    }
    img_->fromFramebuffer(fb->buf, fb->width, fb->height);
    esp_camera_fb_return(fb);
    return img_;
}
