idf_component_register( SRCS "test_barcode_reader.cpp" "barcode_reader.cpp"
                        INCLUDE_DIRS ""
                        REQUIRES unity
                        REQUIRES barcode_reader)

add_compile_definitions(UNIT_TESTING)
