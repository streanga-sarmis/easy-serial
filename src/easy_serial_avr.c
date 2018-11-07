#ifdef __AVR__

#include <assert.h>

#include "arch/easy_serial_avr.h"

void serial_usart_init(){
    UBRR0H = (u8)(BAUDRATE_HELPER >> 8);
    UBRR0L = (u8)(BAUDRATE_HELPER);
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = ((1 << UCSZ00) | (1 << UCSZ01));
}

void serial_usart_write(u8 data){
    while(!(UCSR0A & ( 1 << UDRE0)));
    UDR0 = data;
}

void serial_usart_writes(char* string){
    while(*string != '\0'){
        serial_usart_write(*string);
        string++;
    }
}

u8 serial_usart_read(){
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

#endif