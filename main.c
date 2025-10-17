/**
 ****************************************************************************************
 *
 * @file main.c
 *
 * @brief Bare metal hello world example.
 *
 * The MIT License (MIT)
 * Copyright (c) 2023 Dialog Semiconductor
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 ****************************************************************************************
 */

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "hw_watchdog.h"
#include "hw_clk.h"
#include "hw_gpio.h"
#include "hw_sys.h"
#include "hw_oqspi.h"

#define P9222_EN_PORT   HW_GPIO_PORT_2
#define P9222_EN_PIN    HW_GPIO_PIN_7

#define SCL_EN_PORT     HW_GPIO_PORT_2
#define SCL_EN_PIN      HW_GPIO_PIN_12

int main( void )
{
        hw_watchdog_freeze();

        hw_gpio_configure_pin_power(P9222_EN_PORT, P9222_EN_PIN, HW_GPIO_POWER_VDD1V8P);
        hw_gpio_set_pin_function(P9222_EN_PORT, P9222_EN_PIN, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
        hw_gpio_pad_latch_enable(P9222_EN_PORT, P9222_EN_PIN);

        hw_gpio_configure_pin_power(SCL_EN_PORT, SCL_EN_PIN, HW_GPIO_POWER_VDD1V8P);
        hw_gpio_set_pin_function(SCL_EN_PORT, SCL_EN_PIN, HW_GPIO_MODE_OUTPUT, HW_GPIO_FUNC_GPIO);
        hw_gpio_pad_latch_enable(SCL_EN_PORT, SCL_EN_PIN);

        for ( ;; ) {
                hw_gpio_set_active(P9222_EN_PORT, P9222_EN_PIN);
                hw_gpio_set_active(SCL_EN_PORT, SCL_EN_PIN);
                printf("Active\n");
                fflush(stdout);
                hw_clk_delay_usec(1000000);

                hw_gpio_set_inactive(P9222_EN_PORT, P9222_EN_PIN);
                hw_gpio_set_inactive(SCL_EN_PORT, SCL_EN_PIN);
                printf("Inactive\n");
                fflush(stdout);
                hw_clk_delay_usec(1000000);
        }

}
