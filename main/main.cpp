/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>



#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_camera.h"
#include "cam.hpp"
#include "esp_log.h"

extern "C" void app_main() {
    camera_config_t config = get_default_camera_config();
    Camera cam(config);
    
    while (true) {
        camera_fb_t* fb = cam.capture();
        if (fb) {
            ESP_LOGI("MAIN", "Captured frame");
            cam.release(fb);
        } else {
            ESP_LOGE("MAIN", "Capture failed");
        }

        vTaskDelay(pdMS_TO_TICKS(2000));  // 2s delay cuz monitor went crazy
    }

    
}
