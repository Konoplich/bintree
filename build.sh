#!/bin/bash

rm ./ok

gcc main.c -o ok -L. -lbintree -Wl,-rpath,.
