#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


void gpio_callback(uint gpio, uint32_t events) {
    printf("button pressed");
}

int main() {
    stdio_init_all();
    sleep_ms(3000);
    
    int BUTTON_PIN = 2;
    printf("Hello GPIO IRQ\n");
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_RISE, true, &gpio_callback);
    // Wait forever
    while (1);
}


