idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES cam
                       REQUIRES esp32-camera
                       REQUIRES spi_flash
                       )

