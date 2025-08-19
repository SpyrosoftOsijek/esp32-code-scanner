idf_component_register(SRCS "wifi_post.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_wifi nvs_flash esp_http_client json
)
