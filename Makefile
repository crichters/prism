CC=gcc
BUILD_DIR=./build

IFLAGS=-I ./extern/include -I ./include
LFLAGS=-L ./extern/lib
# LIBS=-l glfw3 -lm
VULKAN_LIBS=-lglfw3 -lvulkan -lm

# If Opengl/GLFW
# PRISM_OBJS=prism_util.o glad.o gl_window_api.o

# if Vulkan/GLFW
PRISM_OBJS=prism_util.o vulkan_window_api.o

BUILD_OBJS=$(addprefix ${BUILD_DIR}/,$(PRISM_OBJS))

# prism: ./src/main.c ${BUILD_OBJS} 
#	${CC} $^ -o ${BUILD_DIR}/$@ ${IFLAGS} ${LFLAGS} ${LIBS}

prism: ./src/main.c ${BUILD_OBJS} 
	${CC} $^ -o ${BUILD_DIR}/$@ ${IFLAGS} ${LFLAGS} ${VULKAN_LIBS}

${BUILD_DIR}/prism_util.o: ./src/prism_utils/util.c
	${CC} -c $^ -o $@ ${IFLAGS}

${BUILD_DIR}/glad.o: ./extern/GLAD/glad.c
	${CC} -c $^ -o $@ ${IFLAGS}

${BUILD_DIR}/vulkan_window_api.o: ./src/glfw_window_api/vulkan_window_api.c
	${CC} -c $^ -o $@ ${IFLAGS}

${BUILD_DIR}/gl_window_api.o: ./src/glfw_window_api/gl_window.c
	${CC} -c $^ -o $@ ${IFLAGS}



compile_commands:
	bear -- make && mv compile_commands.json ./build
