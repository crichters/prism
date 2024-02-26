#!/bin/bash


docker run -it --rm \
    -v ./output:/output \
    -e HOST_UID=`id -u` \
    -e HOST_GID=`id -g` \
    glfw_compiler:latest

mv -f ./output/GLFW ../include/GLFW
mv -f ./output/libglfw3.a ../lib/libglfw3.a
