#!/bin/bash
# Install some dependencies
sudo apt install gcc
gcc --version

# Linter
sudo apt install cppcheck clang
cppcheck --version
clang --version