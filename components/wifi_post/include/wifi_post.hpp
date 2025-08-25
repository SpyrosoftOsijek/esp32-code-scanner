#pragma once

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_http_client.h"
#include "cJSON_Utils.h"

#define MAX_FAILURES 10

#define WIFI_SUCCESS BIT0
#define WIFI_FAILURE BIT1

esp_err_t connect_wifi(void);
void send_barcode_post(const char *barcode);
