/*
 * SPDX-FileCopyrightText: 2015-2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */ 
#include <stdio.h>

#include <string.h>
#include "unity.h"
#include "unity_test_utils.h"
#include <unity_test_runner.h>
#include <iostream>

static void print_banner(const char * text);


extern "C" void app_main(void) {
    print_banner("Running Camera component unit tests");

    UNITY_BEGIN();              
    unity_run_all_tests();
    UNITY_END();                
}
static void print_banner(const char* text)
{
    std::cout << "\n#### " << text << " #####\n\n";
}