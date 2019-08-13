#!/bin/bash

# Create binary directory if not existant
output=$(ls | grep bin)
if [ -z "$output" ]
then
  mkdir bin
fi

g++ -std=c++11 test/test_runner.cpp -o bin/test.out -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
chmod 700 bin/test.out
