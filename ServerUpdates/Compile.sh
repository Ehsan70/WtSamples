#!/bin/sh

g++ -g -o main main.cpp  -L/usr/lib -I/usr/include  -latomic -lrt -lpthread -lm -ldl -lueye_api -lwt -lwthttp -std=c++11


exit $?
