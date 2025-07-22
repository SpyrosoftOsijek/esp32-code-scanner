idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES spi_flash cam
                       REQUIRES esp_wifi wifi
                       )

