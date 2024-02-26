BUILD_DIR=./build


prism: src/main.c
	gcc $^ -o ${BUILD_DIR}/$@
