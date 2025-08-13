set (ZXING_READERS true)

configure_file (${CMAKE_CURRENT_LIST_DIR}/include/core/Version.h.in Version.h)

file(GLOB zxing_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/include/core/src/*
    ${CMAKE_CURRENT_LIST_DIR}/include/core/src/oned/*
    ${CMAKE_CURRENT_LIST_DIR}/include/core/src/libzueci/*)


idf_component_register( SRCS ${zxing_SOURCES}
                        INCLUDE_DIRS 
                            "include" 
                            ${CMAKE_CURRENT_BINARY_DIR} 
                            ${CMAKE_CURRENT_LIST_DIR}/include/core/src/)
