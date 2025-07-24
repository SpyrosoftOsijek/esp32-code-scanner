#pragma once // same as ifndef endif

// gives us access to methods

class Camera {
    public:
        bool init();
        void* capture();
        void release(void* fb);

};