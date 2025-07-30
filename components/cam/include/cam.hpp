#pragma once // same as ifndef endif
#include <iostream>
#include "esp_camera.h"

// gives us access to methods
camera_config_t get_default_camera_config();


class Camera {
    public:
        Camera(camera_config_t config);

        Camera();
        
        ~Camera();
        
        Camera(Camera& obj) = delete;

        Camera& operator=(Camera& obj) = delete;

        camera_fb_t* capture();
        void release(camera_fb_t* fb);

private:
        bool init();
        camera_config_t _config;
};