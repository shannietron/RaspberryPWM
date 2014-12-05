#!/bin/bash
#You need to have wiringpi installed. 
#git.drogon.net/wiringPi 
gcc -I/usr/local/include -L/usr/local/lib -lwiringPi pwm.c -o pwm

