#!/bin/bash
# Install some dependencies
sudo apt install gcc
echo "! Installed GCC: "; gcc --version

# Linter
sudo apt install cppcheck
echo "! Installed CPPCheck: "; cppcheck --version
