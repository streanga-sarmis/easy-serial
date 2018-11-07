#ifndef _EASY_SERIAL_WIN32_H_
#define _EASY_SERIAL_WIN32_H_

#include <stdint.h>

#include <windows.h>

#include "easy_serial_general.h"

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

#endif //_EASY_SERIAL_WIN32_H_
