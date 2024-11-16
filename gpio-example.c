#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main()
{
    stdio_init_all();
    sleep_ms(3000); // Without delay we can crash the mcu if we try use usb
    int LED_PIN = 3;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(1) {
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
    }
}