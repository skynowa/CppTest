#!/bin/bash

c++ -g -O0 ./Backtrace.cpp -rdynamic -ldl -fpermissive -o ./Backtrace.exe
./Backtrace.exe
