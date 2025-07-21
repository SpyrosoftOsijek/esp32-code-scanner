#pragma once // same as ifndef endif

#include "esp_camera.h"// gives us access to methods

class Camera {
    public:
        bool init();
        camera_fb_t* capture();
        void release(camera_fb_t*);

};