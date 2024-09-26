#!/bin/bash


CPP_BASE_NAME="./Backtrace_2"

c++ -g -O0 ./${CPP_BASE_NAME}.cpp -rdynamic -ldl -fpermissive -o ./${CPP_BASE_NAME}.exe
./${CPP_BASE_NAME}.exe
