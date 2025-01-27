
CC = g++
CFLAGS = -g -std=c++11 -Wall
SRC_DIR = src
BUILD_DIR = obj
INCLUDE_DIR = include
BIN_DIR = bin
TEST_DIR = tests

# Criação de diretórios necessários
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))


# Alvo principal
all: ${BIN_DIR}/main ${BIN_DIR}/ReversiClass_test ${BIN_DIR}/BoardClass_test ${BIN_DIR}/Connect4Class_test ${BIN_DIR}/TicTacToeClass_test

# Compilação de Board
${BUILD_DIR}/Board.o: ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Board.cpp
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Board.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Board.o

# Compilação de Game
${BUILD_DIR}/Game.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Game.cpp
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Game.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Game.o

# Compilação de Reversi
${BUILD_DIR}/Reversi.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Reversi.hpp ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Reversi.cpp
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Reversi.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Reversi.o

# Compilação de Player
${BUILD_DIR}/Tic_tac_toe.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Tic_tac_toe.hpp ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Tic_tac_toe.cpp
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Tic_tac_toe.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Tic_tac_toe.o

${BUILD_DIR}/Connect4.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Connect4.hpp ${INCLUDE_DIR}/Board.hpp ${SRC_DIR}/Connect4.cpp
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Connect4.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Connect4.o

${BUILD_DIR}/Player.o: ${INCLUDE_DIR}/Player.hpp ${SRC_DIR}/Player.cpp
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Player.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Player.o

# Compilação de Connect4
${BUILD_DIR}/Connect4.o: ${INCLUDE_DIR}/Connect4.hpp ${SRC_DIR}/Connect4.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Connect4.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Connect4.o

# Compilação de Tic_tac_toe
${BUILD_DIR}/Tic_tac_toe.o: ${INCLUDE_DIR}/Tic_tac_toe.hpp ${SRC_DIR}/Tic_tac_toe.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/Tic_tac_toe.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Tic_tac_toe.o
	
# Compilação de main
${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Reversi.hpp ${INCLUDE_DIR}/Board.hpp ${INCLUDE_DIR}/Player.hpp ${INCLUDE_DIR}/Connect4.hpp ${INCLUDE_DIR}/Tic_tac_toe.hpp ${SRC_DIR}/main.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${SRC_DIR}/main.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/main.o

# Linkagem do executável main
${BIN_DIR}/main: ${BUILD_DIR}/main.o ${BUILD_DIR}/Reversi.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Connect4.o ${BUILD_DIR}/Tic_tac_toe.o
	@mkdir -p ${BIN_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/main.o ${BUILD_DIR}/Reversi.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Connect4.o ${BUILD_DIR}/Tic_tac_toe.o -o ${BIN_DIR}/main

# Compilação de ReversiClass_test
${BUILD_DIR}/ReversiClass_test.o: ${TEST_DIR}/ReversiClass_test.cpp ${INCLUDE_DIR}/Reversi.hpp ${INCLUDE_DIR}/Board.hpp ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Player.hpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${TEST_DIR}/ReversiClass_test.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/ReversiClass_test.o

# Linkagem do executável ReversiClass_test
${BIN_DIR}/ReversiClass_test: ${BUILD_DIR}/ReversiClass_test.o ${BUILD_DIR}/Reversi.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o
	@mkdir -p ${BIN_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/ReversiClass_test.o ${BUILD_DIR}/Reversi.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o -o ${BIN_DIR}/ReversiClass_test

# Compilação de BoardClass_test
${BUILD_DIR}/BoardClass_test.o: ${TEST_DIR}/BoardClass_test.cpp ${INCLUDE_DIR}/Board.hpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${TEST_DIR}/BoardClass_test.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/BoardClass_test.o

# Linkagem do executável BoardClass_test
${BIN_DIR}/BoardClass_test: ${BUILD_DIR}/BoardClass_test.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/ReversiClass_test.o
	@mkdir -p ${BIN_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/BoardClass_test.o ${BUILD_DIR}/Board.o -o ${BIN_DIR}/BoardClass_test

# Compilação de Connect4Class_test
${BUILD_DIR}/Connect4Class_test.o: ${TEST_DIR}/Connect4Class_test.cpp ${INCLUDE_DIR}/Connect4.hpp ${INCLUDE_DIR}/Board.hpp ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Player.hpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${TEST_DIR}/Connect4Class_test.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Connect4Class_test.o

# Linkagem do executável Connect4Class_test
${BIN_DIR}/Connect4Class_test: ${BUILD_DIR}/Connect4Class_test.o ${BUILD_DIR}/Connect4.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o
	@mkdir -p ${BIN_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/Connect4Class_test.o ${BUILD_DIR}/Connect4.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o -o ${BIN_DIR}/Connect4Class_test

# Compilação de Player_test.o
${BUILD_DIR}/Player_test.o: ${INCLUDE_DIR}/Player.hpp ${TEST_DIR}/Player_test.cpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${TEST_DIR}/Player_test.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/Player_test.o

# Linkagem do executável Player_test
${BIN_DIR}/Player_test: ${BUILD_DIR}/Player_test.o ${BUILD_DIR}/Player.o
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/Player_test.o ${BUILD_DIR}/Player.o -o ${BIN_DIR}/Player_test
	

# Compilação de TicTacToeClass_test
${BUILD_DIR}/TicTacToeClass_test.o: ${TEST_DIR}/TicTacToeClass_test.cpp ${INCLUDE_DIR}/Tic_tac_toe.hpp ${INCLUDE_DIR}/Game.hpp ${INCLUDE_DIR}/Board.hpp ${INCLUDE_DIR}/Player.hpp
	@mkdir -p ${BUILD_DIR}
	$(CC) $(CFLAGS) -c ${TEST_DIR}/TicTacToeClass_test.cpp -I$(INCLUDE_DIR) -o ${BUILD_DIR}/TicTacToeClass_test.o

# Linkagem do executável TicTacToeClass_test
${BIN_DIR}/TicTacToeClass_test: ${BUILD_DIR}/TicTacToeClass_test.o ${BUILD_DIR}/Tic_tac_toe.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o
	@mkdir -p ${BIN_DIR}
	$(CC) $(CFLAGS) ${BUILD_DIR}/TicTacToeClass_test.o ${BUILD_DIR}/Tic_tac_toe.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Board.o ${BUILD_DIR}/Player.o -o ${BIN_DIR}/TicTacToeClass_test

# Limpeza
clean:
	@rm -f ${BUILD_DIR}/*.o
	@rm -f ${BIN_DIR}/*

# Execução do valgrind em main
valgrind: ${BIN_DIR}/main
	valgrind --leak-check=full ${BIN_DIR}/main

valgrind_reversi: ${BIN_DIR}/ReversiClass_test
	valgrind --leak-check=full ${BIN_DIR}/ReversiClass_test

.PHONY: all clean valgrind
