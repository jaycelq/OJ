#!/bin/bash

input=$1
output=${input/cpp/out}

echo clang++ $input -o $output

clang++ $input -o $output
