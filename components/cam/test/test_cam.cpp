
#include "cam.hpp"
#include "unity.h"
#include "raw_img.hpp"

TEST_CASE("Camera capture returns framebuffer", "[cam]")
{
    Camera cam{};

    std::shared_ptr<rawImg> img = cam.capture();
    TEST_ASSERT_NOT_NULL(img.get());

    TEST_ASSERT_EQUAL_UINT8(IMG_HEIGHT, img->imgHeight());
}
