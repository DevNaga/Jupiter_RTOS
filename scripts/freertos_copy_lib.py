#!/usr/bin/python

#/bin/bash

find . -iname *.c | xargs cp -r /root/Arduino/libraries/FreeRTOS_ARM/src/
find . -iname *.h | xargs cp -r /root/Arduino/libraries/FreeRTOS_ARM/src/
cp -r autosar/autosar.h /root/Arduino/libraries/FreeRTOS_ARM/src/