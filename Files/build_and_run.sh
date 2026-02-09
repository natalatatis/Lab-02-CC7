#!/bin/bash
set -e

echo "Cleaning up previous build files..."
rm -f *.o calculadora.elf calculadora.bin

echo "Assembling root.s..."
arm-none-eabi-as -o root.o OS/root.s

echo "Compiling user layer..."
arm-none-eabi-gcc -c Program/main.c -ILib -IOS -o main.o

echo "Compiling language library..."
arm-none-eabi-gcc -c Lib/stdio.c -ILib -IOS -o stdio.o
arm-none-eabi-gcc -c Lib/string.c -ILib -o string.o

echo "Compiling OS layer..."
arm-none-eabi-gcc -c OS/os.c -IOS -o os.o

echo "Linking object files..."
arm-none-eabi-gcc -T linker.ld \
  root.o main.o stdio.o string.o os.o \
  -nostdlib -lgcc \
  -o calculadora.elf



echo "Converting ELF to binary..."
arm-none-eabi-objcopy -O binary calculadora.elf calculadora.bin

echo "Running QEMU..."
qemu-system-arm -M versatilepb -nographic -kernel calculadora.elf
