#!/bin/bash

# Create binary directory if not existant
output=$(ls | grep bin)
if [ -z "$output" ]
then
  mkdir bin
fi

g++ src/main.cpp -o bin/main.out -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
chmod 700 bin/main.out
