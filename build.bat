avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o avr_test.o avr_test.c -Iinclude
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o easy_serial_win32.o src/easy_serial_win32.c -Iinclude
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o easy_serial_avr.o src/easy_serial_avr.c -Iinclude
avr-gcc -mmcu=atmega328p avr_test.o easy_serial_win32.o easy_serial_avr.o -o avr_test
avr-objcopy -O ihex -R .eeprom avr_test avr_test.hex
avrdude -F -V -c arduino -p ATMEGA328P -P com5 -b 57600 -U flash:w:avr_test.hex