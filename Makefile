CC = g++
CFLAGS = -g -std=c++11 -Wall
SRC_DIR = src
BUILD_DIR = obj
INCLUDE_DIR = include
BIN_DIR = bin
TEST_DIR = tests

$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

all: ${BIN_DIR}/main ${BIN_DIR}/Player_test

${BUILD_DIR}/Board.o: ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Board.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Board.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Board.o

${BUILD_DIR}/Game.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Game.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Game.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Game.o

${BUILD_DIR}/Reversi.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Reversi.hpp ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Reversi.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Reversi.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Reversi.o

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player.hpp ${SRC_DIR}/Player.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Player.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Player.o

${BUILD_DIR}/Connect4.o: ${INCLUDE_DIR}/Connect4.hpp ${SRC_DIR}/Connect4.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Connect4.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Connect4.o

${BUILD_DIR}/Tic_tac_toe.o: ${INCLUDE_DIR}/Tic_tac_toe.hpp ${SRC_DIR}/Tic_tac_toe.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Tic_tac_toe.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Tic_tac_toe.o

${BUILD_DIR}/Player_test.o: ${INCLUDE_DIR}/Player.hpp ${TEST_DIR}/Player_test.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${TEST_DIR}/Player_test.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Player_test.o

${BIN_DIR}/Player_test: ${BUILD_DIR}/Player_test.o ${BUILD_DIR}/Player.o
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/Player_test.o ${BUILD_DIR}/Player.o -o ${BIN_DIR}/Player_test
	
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Reversi.hpp ${INCLUDE_DIR}/Board.hpp ${INCLUDE_DIR}/Player.hpp ${INCLUDE_DIR}/Connect4.hpp ${INCLUDE_DIR}/Tic_tac_toe.hpp ${SRC_DIR}/main.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/main.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/main.o

${BIN_DIR}/main: ${BUILD_DIR}/main.o ${BUILD_DIR}/Reversi.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Connect4.o ${BUILD_DIR}/Tic_tac_toe.o
	@mkdir -p ${BIN_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/main.o ${BUILD_DIR}/Reversi.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Connect4.o ${BUILD_DIR}/Tic_tac_toe.o -o ${BIN_DIR}/main

clean:
	@rm -f ${BUILD_DIR}/*.o
	@rm -f ${BIN_DIR}/*

valgrind: ${BIN_DIR}/main
	valgrind --leak-check=full ${BIN_DIR}/main

.PHONY: all clean valgrind