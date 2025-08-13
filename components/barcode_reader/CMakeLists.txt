idf_component_register(
    SRCS "barcode_reader.cpp"
    INCLUDE_DIRS "include"
    REQUIRES zxing rawimg
)

target_compile_options(${COMPONENT_LIB} PRIVATE -fexceptions)
target_compile_definitions(${COMPONENT_LIB} PRIVATE ZXING_USE_CPP17=1 ZXING_NO_EXCEPTIONS=0)
