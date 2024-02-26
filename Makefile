BUILD_DIR=./build

IFLAGS=-I ./extern/include

prism: src/main.c
	gcc $^ -o ${BUILD_DIR}/$@ -I ./extern/include

compile_commands:
	bear -- make && mv compile_commands.json ./build
