SRC_DIR := ./src
TMP_DIR := ./tmp

SRC_FILES := ${SRC_DIR}/*.cpp
O_FILES := *.o

comp:
	g++ -c ${SRC_FILES}
	g++  ${O_FILES} -o ${TMP_DIR}/Run.exe
	rm ${O_FILES}