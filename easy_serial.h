#ifndef _EASY_SERIAL_H_
#define _EASY_SERIAL_H_

#include <stdint.h>

#define ES_TRUE 0x01
#define ES_FALSE 0x00

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#ifdef _WIN32

#include <windows.h>

typedef struct serial {
    u8 connected;
    HANDLE fileHandler;
    DCB deviceControl;
} serial_t;

void serial_init(serial_t* serial, char* port, u32 bps);

void serial_write(serial_t* serial, u8 data);

void serial_read(serial_t* serial, u8* container, u32 bytes);

u8 serial_readb(serial_t* serial);

void serial_close(serial_t* serial);

#endif

#ifdef __AVR__

#include <avr/io.h>

#define BAUDRATE 57600 // I use an arduino nano with an ATmega328p au, so it can handle it
#define BAUDRATE_HELPER (((F_CPU / (BAUDRATE * 16UL))) - 1)

static inline void serial_usart_init(){
    UBRR0H = (u8)(BAUDRATE_HELPER >> 8);
    UBRR0L = (u8)(BAUDRATE_HELPER);
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = ((1 << UCSZ00) | (1 << UCSZ01));
}

static inline void serial_usart_write(u8 data){
    while(!(UCSR0A & ( 1 << UDRE0)));
    UDR0 = data;
}

static inline void serial_usart_writes(char* string){
    while(*string != '\0'){
        serial_usart_write(*string);
        string++;
    }
}

static inline u8 serial_usart_read(){
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

#endif

#endif //_EASY_SERIAL_H_
