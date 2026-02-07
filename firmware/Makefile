.PHONY: all test clean
CC=gcc
CFLAGS=-Wall -Wextra -g -O0 -Iinclude

FW_SRC=src/firmware.c
APP_SRC=src/main.c
TEST=tests/test_sensor.c

all:
	$(CC) $(CFLAGS) -o firmware_bin $(FW_SRC) $(APP_SRC)

test:
	$(CC) $(CFLAGS) -o test_bin $(FW_SRC) $(TEST) 
	./test_bin
clean:
	rm -f firmware_bin test_bin
