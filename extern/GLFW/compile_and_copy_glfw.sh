#!/bin/bash

git clone https://github.com/glfw/glfw.git
mkdir build

cmake -S ./glfw -B build

cd build 

make -j

cp src/libglfw3.a /output
cp -r ../glfw/include/GLFW /output

chown -R $HOST_UID:$HOST_GID /output
