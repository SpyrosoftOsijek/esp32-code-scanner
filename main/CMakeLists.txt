idf_component_register( SRCS "main.cpp"
                        INCLUDE_DIRS "."
                        REQUIRES barcode_reader
                        REQUIRES spi_flash)
