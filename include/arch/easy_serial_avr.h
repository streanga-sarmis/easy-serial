#ifndef _EASY_SERIAL_AVR_H_
#define _EASY_SERIAL_AVR_H_

#include <avr/io.h>

#include "easy_serial_general.h"

#define BAUDRATE 57600 // I use an arduino nano with an ATmega328p au, so it can handle it
#define BAUDRATE_HELPER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void serial_usart_init();

void serial_usart_write(u8 data);

void serial_usart_writes(char* string);

u8 serial_usart_read();

#endif //_EASY_SERIAL_AVR_H_