#include <avr/io.h>
#include <util/delay.h>

#include "easy_serial.h"

int main (){
    serial_usart_init();
    for(;;){
        serial_usart_write(0x70);
        serial_usart_write(0x71);
        serial_usart_write(0x71);
        serial_usart_write(0x70);
        _delay_ms(500);
    }
}