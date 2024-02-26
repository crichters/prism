FROM ubuntu:latest


RUN apt-get update
RUN apt-get install -y git curl libxkbcommon-dev xorg-dev libwayland-dev cmake
RUN apt-get clean

RUN mkdir /src
RUN mkdir /output

WORKDIR /src

ADD compile_and_copy_glfw.sh /src/compile.sh

CMD ["/bin/bash", "./compile.sh"]
