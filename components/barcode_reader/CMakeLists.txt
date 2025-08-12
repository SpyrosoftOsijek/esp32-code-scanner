set (ZXING_READERS true)


idf_component_register( SRCS "barcode_reader.cpp"

                                
                        INCLUDE_DIRS "include"
                        "../zxing/include"
                        REQUIRES zxing)