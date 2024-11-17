#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"


void core1_entry() {
    multicore_lockout_victim_init();
    while(1) {
        multicore_lockout_start_blocking();
        printf("Hello Core1");
        multicore_lockout_end_blocking();
    }     
}

int main() {
    stdio_init_all();
    sleep_ms(3000); // Without delay we can crash the mcu if we try use usb
    printf("Hello, multicore!\n");
    // enable the second core and allow for multicore lockout 
    // to prevent double printing to stdout effectively a mutex
    multicore_lockout_victim_init();
    multicore_launch_core1(core1_entry);

    while(1) {
        multicore_lockout_start_blocking();
        printf("Hello Core0");
        multicore_lockout_end_blocking();
    }
}