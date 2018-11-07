#include "easy_serial.h"

#include <assert.h>

#ifdef _WIN32
// _WIN32 __unix__

void serial_init(serial_t* serial, char* port, u32 bps){
    serial->fileHandler = CreateFileA(port, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    serial->connected = ES_FALSE;
    
    if (serial->fileHandler != INVALID_HANDLE_VALUE){
        serial->connected = ES_TRUE;

        serial->deviceControl.BaudRate = bps;
        serial->deviceControl.ByteSize = sizeof(u8);
        serial->deviceControl.Parity = 0;
        serial->deviceControl.StopBits = ONESTOPBIT;
        GetCommState(serial->fileHandler, &serial->deviceControl);
        SetCommState(serial->fileHandler, &serial->deviceControl);
        // TODO add error handling
    }
}

void serial_write(serial_t* serial, u8 byte){
    assert(serial->connected);
    DWORD bytesWritten = 0;
    WriteFile(serial->fileHandler, &byte, sizeof(byte), &bytesWritten, NULL);
}

void serial_read(serial_t* serial, u8* container, u32 bytes){
    assert(serial->connected);
    DWORD bytesRead = 0;
    ReadFile(serial->fileHandler, container, bytes, &bytesRead, NULL);
    // TODO add error checking, like, redfile return FALSE
}

u8 serial_readb(serial_t* serial){
    u8 result;
    serial_read(serial, &result, 1);
    return result;
}

void serial_close(serial_t* serial){
    if (serial->connected){
        CloseHandle(serial->fileHandler);
    }
}
#endif