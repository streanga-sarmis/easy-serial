#ifndef _EASY_SERIAL_H_
#define _EASY_SERIAL_H_

#ifdef _WIN32
#include "arch/easy_serial_win32.h"
#elif defined __AVR__
#include "arch/easy_serial_avr.h"
#endif

#endif //_EASY_SERIAL_H_