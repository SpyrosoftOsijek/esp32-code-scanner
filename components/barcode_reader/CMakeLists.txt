set (ZXING_READERS true)
set(zxing_ROOT
    "${CMAKE_CURRENT_LIST_DIR}/../zxing")

file(GLOB zxing_SOURCES
    "${zxing_ROOT}/include/core/src/*cpp"
)

idf_component_register( SRCS "barcode_reader.cpp"
                        ${zxing_SOURCES}
                                
                        INCLUDE_DIRS include
                        ${zxing_ROOT}/include
                        ${zxing_ROOT}/include/core/src
                        REQUIRES zxing)