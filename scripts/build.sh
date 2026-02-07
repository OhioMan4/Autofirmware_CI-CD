#!/bin/bash
set -e

echo "[BUILD] Compiling firmware..."
gcc -Wall -Wextra -g -Isinclude src/main.c -o build/firmware_bin
echo "[BUILD] Done"
