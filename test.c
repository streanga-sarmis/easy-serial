#include "easy_serial.h"
#include <stdio.h>

int main(){

    serial_t serial;

    serial_init(&serial, "\\\\.\\COM5", 57600);

    printf(" %x\n %x\n %x\n %x\n", 
        serial_readb(&serial),
        serial_readb(&serial),
        serial_readb(&serial),
        serial_readb(&serial));

    serial_close(&serial);

    return 0;
}