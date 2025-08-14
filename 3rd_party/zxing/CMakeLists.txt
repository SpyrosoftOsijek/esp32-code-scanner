file(GLOB zxing_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/zxing/core/src/*
    ${CMAKE_CURRENT_LIST_DIR}/zxing/core/src/oned/*
    ${CMAKE_CURRENT_LIST_DIR}/zxing/core/src/libzueci/*)


idf_component_register( SRCS ${zxing_SOURCES}
                        INCLUDE_DIRS 
                            "zxing" 
                            ${CMAKE_CURRENT_BINARY_DIR} 
                            ${CMAKE_CURRENT_LIST_DIR}/zxing/core/src/)

target_compile_definitions(${COMPONENT_LIB} PRIVATE
    ZXING_READERS=1
    ZXING_USE_CPP17=1
    ZXING_NO_EXCEPTIONS=0
)

target_compile_options(${COMPONENT_LIB} PRIVATE -fexceptions)