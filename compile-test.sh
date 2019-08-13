#!/bin/bash

# Create binary directory if not existant
output=$(ls | grep bin)
if [ -z "$output" ]
then
  mkdir bin
fi

# Compile test code
g++ -std=c++11 test/test_runner.cpp -o bin/test.out -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic

# Modify execution permissions of file
chmod 700 bin/test.out

# Execute compiled machine code to test project
bin/test.out
