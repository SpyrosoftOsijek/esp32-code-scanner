#include "wifi_post.hpp"

#include "esp_netif.h"

// event group to contain status information
static EventGroupHandle_t wifi_event_group;

static int s_retry_num = 0;

static const char *TAG = "WIFI";

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        ESP_LOGI(TAG, "Connecting to AP...");
        esp_wifi_connect();
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        if (s_retry_num < MAX_FAILURES)
        {
            ESP_LOGI(TAG, "Reconnecting to AP...");
            esp_wifi_connect();
            s_retry_num++;
        }
        else
        {
            xEventGroupSetBits(wifi_event_group, WIFI_FAILURE);
        }
    }
}

static void ip_event_handler(void *arg, esp_event_base_t event_base,
                             int32_t event_id, void *event_data)
{
    if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "STA IP: " IPSTR, IP2STR(&event->ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(wifi_event_group, WIFI_SUCCESS);
    }
}

esp_err_t connect_wifi()
{
    int status = WIFI_FAILURE;

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_create_default_wifi_sta();

    // setup wifi station with the default wifi configuration
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    wifi_event_group = xEventGroupCreate();

    esp_event_handler_instance_t wifi_handler_event_instance;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &wifi_handler_event_instance));

    esp_event_handler_instance_t got_ip_event_instance;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &ip_event_handler,
                                                        NULL,
                                                        &got_ip_event_instance));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = "HONOR 90",
            .password = "jpbo2636",
            .scan_method = WIFI_FAST_SCAN,
            .bssid_set = false,
            .bssid = {0},
            .channel = 0,
            .listen_interval = 3,
            .sort_method = WIFI_CONNECT_AP_BY_SIGNAL,
            .threshold = {
                .rssi = -127,
                .authmode = WIFI_AUTH_WPA2_WPA3_PSK,
                .rssi_5g_adjustment = 0,
            },

            .pmf_cfg = {.capable = true, .required = false},
            .rm_enabled = 0,
            .btm_enabled = 0,
            .mbo_enabled = 0,
            .ft_enabled = 0,
            .owe_enabled = 0,
            .transition_disable = 0,
            .reserved1 = 0,
            .sae_pwe_h2e = WPA3_SAE_PWE_UNSPECIFIED,
            .sae_pk_mode = WPA3_SAE_PK_MODE_DISABLED,
            .failure_retry_cnt = 0,
            .he_dcm_set = 0,
            .he_dcm_max_constellation_tx = 0,
            .he_dcm_max_constellation_rx = 0,
            .he_mcs9_enabled = 0,
            .he_su_beamformee_disabled = 0,
            .he_trig_su_bmforming_feedback_disabled = 0,
            .he_trig_mu_bmforming_partial_feedback_disabled = 0,
            .he_trig_cqi_feedback_disabled = 0,
            .vht_su_beamformee_disabled = 0,
            .vht_mu_beamformee_disabled = 0,
            .vht_mcs8_enabled = 0,
            .reserved2 = 0,
            .sae_h2e_identifier = "\0",

        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));

    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "STA initialization complete");

    EventBits_t bits = xEventGroupWaitBits(wifi_event_group,
                                           WIFI_SUCCESS | WIFI_FAILURE,
                                           pdFALSE,
                                           pdFALSE,
                                           portMAX_DELAY);

    if (bits & WIFI_SUCCESS)
    {
        ESP_LOGI(TAG, "Connected to ap");
        status = WIFI_SUCCESS;
    }
    else if (bits & WIFI_FAILURE)
    {
        ESP_LOGI(TAG, "Failed to connect to ap");
        status = WIFI_FAILURE;
    }
    else
    {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
        status = WIFI_FAILURE;
    }

    /* The event will not be processed after unregister */
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, got_ip_event_instance));
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_handler_event_instance));
    vEventGroupDelete(wifi_event_group);

    return status;
}

void send_barcode_post(const char *barcode)
{

    esp_http_client_config_t config = {};
    config.url = "https://webhook.site/81ceff9a-6bf4-43a8-8d1b-51858e21500c",
    config.method = HTTP_METHOD_POST;
    config.cert_pem = NULL;

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (client == NULL)
    {
        ESP_LOGE("HTTP_TAG", "Failed to initialize HTTP Client!");
        return;
    }

    esp_http_client_set_header(client, "Content-Type", "application/json");

    char post_data[64];

    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "barcode", barcode);
    char *json_str = cJSON_PrintUnformatted(root);

    strncpy(post_data, json_str, sizeof(post_data));

    cJSON_Delete(root);
    free(json_str);

    esp_http_client_set_post_field(client, post_data, sizeof(post_data));

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK)
    {
        int status = esp_http_client_get_status_code(client);
        ESP_LOGI("HTTP_TAG", "POST succeeded, status = %d", status);
    }
    else
    {
        ESP_LOGE("HTTP_TAG", "HTTP POST failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
}
