
#include "barcode_reader.hpp"
#include "esp_log.h"
#include "unity.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


const char* TAG = "BARCODE_READER_TEST";


extern "C" void setUp(void) {
    
}

extern "C" void tearDown(void) {
    
}


TEST_CASE("Reader returns no", "[barcode_reader]"){

    std::cout << "no" << '\n';
    TEST_ASSERT_TRUE(true);

}


TEST_CASE("Reader returns yes", "[barcode_reader]"){

    std::cout << "yes" << '\n';
    TEST_ASSERT_TRUE(true);

}