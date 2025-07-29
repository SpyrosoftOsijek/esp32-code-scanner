idf_component_register(SRCS "cam.cpp"
                       INCLUDE_DIRS "include"
                       REQUIRES esp32-camera
                       REQUIRES unity idf_test)
