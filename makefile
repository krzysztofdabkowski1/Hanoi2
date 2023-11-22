
SRC_DIR=src/
OUTPUT_DIR= objs/

output: main ring tower hanoi game
	@echo "Linking output..."
	@g++  ${OUTPUT_DIR}main.o ${OUTPUT_DIR}CTower.o ${OUTPUT_DIR}CRing.o ${OUTPUT_DIR}CBoard.o  ${OUTPUT_DIR}CGame.o ${OUTPUT_DIR}CHanoiResolver.o -o output.exe

main: ring tower board hanoi game
	@echo "Compiling Main..."
	@g++ -c ${SRC_DIR}main.cpp -o ${OUTPUT_DIR}main.o 

game: ${SRC_DIR}CGame.h ${SRC_DIR}CGame.cpp
	@echo "Compiling Game..."
	@g++ -c ${SRC_DIR}CGame.cpp -o ${OUTPUT_DIR}CGame.o

hanoi: ${SRC_DIR}CHanoiResolver.h ${SRC_DIR}CHanoiResolver.cpp
	@echo "Compiling HanoiResolver..."
	@g++ -c ${SRC_DIR}CHanoiResolver.cpp -o ${OUTPUT_DIR}CHanoiResolver.o

board: ${SRC_DIR}CBoard.h ${SRC_DIR}CBoard.cpp 
	@echo "Compiling Board..."
	@g++ -c ${SRC_DIR}CBoard.cpp -o ${OUTPUT_DIR}CBoard.o

tower: ${SRC_DIR}CTower.h ${SRC_DIR}CTower.cpp
	@echo "Compiling Tower..."
	@g++ -c ${SRC_DIR}CTower.cpp -o ${OUTPUT_DIR}CTower.o

ring: ${SRC_DIR}CRing.h ${SRC_DIR}CRing.cpp
	@echo "Compiling Ring..."
	@g++ -c ${SRC_DIR}CRing.cpp -o ${OUTPUT_DIR}CRing.o

clean:
	@echo "Cleaning objs files..."
	@rm -f ${OUTPUT_DIR}*.o
	@echo "Cleaning *.exe files..."
	@rm -f *.exe