file(GLOB_RECURSE zxing_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/zxing/core/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/zxing/core/src/libzueci/*.c"
    )

idf_component_register( SRCS ${zxing_SOURCES}
                        INCLUDE_DIRS 
                            ${CMAKE_CURRENT_LIST_DIR}/zxing/core
                            ${CMAKE_CURRENT_LIST_DIR}/zxing/core/src)

target_compile_definitions(${COMPONENT_LIB} PRIVATE
    ZXING_READERS=1
    ZXING_USE_CPP17=1
    ZXING_NO_EXCEPTIONS=0
)

target_compile_options(${COMPONENT_LIB} PRIVATE -fexceptions)