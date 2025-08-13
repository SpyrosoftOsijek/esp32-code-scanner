set(ZXING_VENDOR_ROOT ${CMAKE_CURRENT_LIST_DIR}/include/core)

file(GLOB_RECURSE ZXING_SRC
    "${ZXING_VENDOR_ROOT}/src/*.cpp"
    "${ZXING_VENDOR_ROOT}/src/libzueci/*"

)

idf_component_register(
    SRCS         ${ZXING_SRC}
    INCLUDE_DIRS
        "${ZXING_VENDOR_ROOT}"
        "${ZXING_VENDOR_ROOT}/src"
)

target_compile_definitions(${COMPONENT_LIB} PRIVATE
    ZXING_READERS=1
    ZXING_USE_CPP17=1
    ZXING_NO_EXCEPTIONS=0
)

target_compile_options(${COMPONENT_LIB} PRIVATE -fexceptions)
