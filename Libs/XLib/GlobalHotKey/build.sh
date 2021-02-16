#!/bin/bash

g++ ./xgrabkey_2.c `pkg-config --cflags --libs x11`
