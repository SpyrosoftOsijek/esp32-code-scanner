/*
 * SPDX-FileCopyrightText: 2015-2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>
#include "unity.h"
#include <unity_test_runner.h>


static void print_banner(const char * text);


extern "C" void app_main(void) {
    UNITY_BEGIN();              
    unity_run_all_tests();
    UNITY_END();                
}
