#!/bin/bash

esptool.py -p $(ls /dev/tty.wchusbserial*) -b 230400 write_flash -ff 40m -fm qio -fs 4m 0x00000 binaries/0x00000.bin 0x0a000 binaries/0x0a000.bin 0x4A000 binaries/spiff_rom.bin
