#pragma once

#include <array>
#include <memory>

// our img format
#define IMG_WIDTH 320
#define IMG_HEIGHT 240

struct rawImg
{

    std::array<std::array<uint8_t, IMG_WIDTH>, IMG_HEIGHT> image;

    size_t imgHeight()
    {
        return image.size();
    }

    void fromFramebuffer(uint8_t *buf, size_t width, size_t height)
    {
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                image[row][col] = buf[row * width + col];
            }
        }
    }

    uint8_t getPixel(int row, int col)
    {
        return image[row][col];
    }
};