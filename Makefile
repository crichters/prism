BUILD_DIR=./build

GLAD_FILES=./extern/GLAD/glad.c
IFLAGS=-I ./extern/include
LFLAGS=-L ./extern/lib
LIBS=-l glfw3 -lm

prism: src/main.c ${GLAD_FILES}
	gcc $^ -o ${BUILD_DIR}/$@ ${IFLAGS} ${LFLAGS} ${LIBS}

compile_commands:
	bear -- make && mv compile_commands.json ./build
