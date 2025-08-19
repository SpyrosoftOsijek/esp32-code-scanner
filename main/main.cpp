#include "wifi_post.hpp"

extern "C" void app_main()
{

  esp_err_t status = WIFI_FAILURE;

  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
  {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  status = connect_wifi();
  if (WIFI_SUCCESS != status)
  {
    ESP_LOGI("WIFI", "Failed to associate to AP, dying...");
    return;
  }

  const char *test_barcode = "12345";

  send_barcode_post(test_barcode);

  vTaskDelay(pdMS_TO_TICKS(1000));
}
