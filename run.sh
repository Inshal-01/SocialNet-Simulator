#!/bin/bash
# ------------------------------------------------------------
# SocialNet Simulator — Run Script
# Author: Inshal X-A
# Purpose: Compile and execute the SocialNet simulator
# ------------------------------------------------------------

echo "Compiling project..."
g++ -std=c++17 main.cpp -o socialnet

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "----------------------------------"
    echo "Starting SocialNet Simulator..."
    echo "----------------------------------"
    ./socialnet
else
    echo "Compilation failed! Please check for errors."
fi
