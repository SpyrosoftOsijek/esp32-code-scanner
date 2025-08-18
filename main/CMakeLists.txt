idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES cam spi_flash barcode_reader esp_wifi wifi_post 
                        )

