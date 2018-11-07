#include <avr/io.h>
#include <util/delay.h>

#include "easy_serial.h"

int main (){
    for(;;){
        serial_usart_write(0x69);
        serial_usart_write(0x00);
        serial_usart_write(0x00);
        serial_usart_write(0x69);
        _delay_ms(500);
    }
}