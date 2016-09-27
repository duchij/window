#! /bin/bash
dir=$(pwd) 

g++ -o $dir/window $dir/window.cpp `/opt/libpng12/bin/libpng-config --ldflags`
