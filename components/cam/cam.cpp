#include "esp_log.h"
#include "cam.hpp"

Camera::Camera(camera_config_t config) : _config(config)
{
    esp_err_t err = esp_camera_init(&_config);
    if (err != ESP_OK)
    {
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
{
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb)
    {
        throw CameraCaptureException("Capture failed!");
    }
    img_->fromFramebuffer(fb->buf, fb->width, fb->height);
    esp_camera_fb_return(fb);
    return img_;
}
