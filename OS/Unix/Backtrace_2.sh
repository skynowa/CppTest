#!/bin/bash


CPP_BASE_NAME="./Backtrace_2"

echo "Compile ${CPP_BASE_NAME}.cpp ..."
c++ -g -O0 -rdynamic ./${CPP_BASE_NAME}.cpp -ldl -fno-omit-frame-pointer -fpermissive -o ./${CPP_BASE_NAME}.exe

echo "Run..."
./${CPP_BASE_NAME}.exe
