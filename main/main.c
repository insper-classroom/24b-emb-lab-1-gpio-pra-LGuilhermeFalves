/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int led_pin = 16;
const int led_pin1 = 18;
const int led_pin2 = 19;
const int led_pin3 = 20;
const int led_pin4 = 21;

const int button_pin = 18;

int main() {
    stdio_init_all();

    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);   

    gpio_init(led_pin1);
    gpio_set_dir(led_pin1, GPIO_OUT);

    gpio_init(led_pin2);
    gpio_set_dir(led_pin2, GPIO_OUT);

    gpio_init(led_pin3);
    gpio_set_dir(led_pin3, GPIO_OUT);

    gpio_init(led_pin4);
    gpio_set_dir(led_pin4, GPIO_OUT); 

    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_IN);
    gpio_pull_up(button_pin);

    while (true) {
        printf("Hello, world!\n");

        if (!gpio_get(button_pin)) {
            gpio_put(led_pin, 1);
            for (int i = 0; i < 515; i++) {
                gpio_put(led_pin1, 1);
                sleep_ms(5);
                gpio_put(led_pin1, 0);
                gpio_put(led_pin2, 1);
                sleep_ms(5);
                gpio_put(led_pin2, 0);
                gpio_put(led_pin3, 1);
                sleep_ms(5);
                gpio_put(led_pin3, 0);
                gpio_put(led_pin4, 1);
                sleep_ms(5);
                gpio_put(led_pin4, 0);
            }
            gpio_put(led_pin1, 0);
            gpio_put(led_pin2, 0);
            gpio_put(led_pin3, 0);
            gpio_put(led_pin4, 0);
            gpio_put(led_pin, 0);
        }
    
        sleep_ms(1000);
    }
}
