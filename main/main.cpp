/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "wifi_component.hpp"
#include "freertos/task.h"
#include <inttypes.h>
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

extern "C" void app_main() {
    
    esp_err_t status = WIFI_FAILURE;

    // init storage
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // connect to wireless AP
	status = connect_wifi();
	if (WIFI_SUCCESS != status)
	{
		ESP_LOGI("WIFI", "Failed to associate to AP, dying...");
		return;
	}

}
