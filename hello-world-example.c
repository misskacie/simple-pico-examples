#include <stdio.h>
#include "pico/stdlib.h"


int main()
{
    stdio_init_all();
    sleep_ms(3000); // Without delay we can crash the mcu if we try use usb

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
