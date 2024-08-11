@echo off
mkdir o >nul 2>&1
clang -Wall -Wextra -Wpedantic -Wno-gnu-binary-literal -Werror -O3 src/*.c -o ./o/main.exe -lgdi32 -lwinmm