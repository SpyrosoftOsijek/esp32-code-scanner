idf_component_register(SRCS "test_cam.cpp"
                    INCLUDE_DIRS ""
                    REQUIRES unity
                    REQUIRES cam
                    )

add_compile_definitions(UNIT_TESTING)
