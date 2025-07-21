/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "camera_component.hpp"
#include "esp_log.h"

extern "C" void app_main() {
    Camera cam;
    if (!cam.init()) {
        ESP_LOGE("MAIN", "Camera failed to initialize");
        while(true)  {
            
        }
        return;
    }

    while (true) {
        camera_fb_t* fb = cam.capture();
        if (fb) {
            ESP_LOGI("MAIN", "Captured frame, size: %d bytes", fb->len);
            cam.release(fb);
        } else {
            ESP_LOGE("MAIN", "Capture failed");
        }

        vTaskDelay(pdMS_TO_TICKS(2000));  // 2s delay cuz monitor went crazy
    }
}
