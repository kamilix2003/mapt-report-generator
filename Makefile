SRC_DIR := ./src

SRC_FILES := ${SRC_DIR}/*.cpp
O_FILES := *.o

comp:
	g++ -c ${SRC_FILES}
	g++  ${O_FILES} -o Run.out
	rm ${O_FILES}