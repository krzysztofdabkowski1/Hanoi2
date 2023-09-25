
SRC_DIR=src/
OUTPUT_DIR= objs/

output: main ring tower hanoi
	@echo "Linking output..."
	@g++  ${OUTPUT_DIR}main.o ${OUTPUT_DIR}tower.o ${OUTPUT_DIR}ring.o ${OUTPUT_DIR}CBoard.o ${OUTPUT_DIR}CHanoiResolver.o -o output.exe

main: ring tower board hanoi
	@echo "Compiling main..."
	@g++ -c ${SRC_DIR}main.cpp -o ${OUTPUT_DIR}main.o 

hanoi: ${SRC_DIR}CHanoiResolver.h ${SRC_DIR}CHanoiResolver.cpp
	@echo "Compiling CHanoiResolver..."
	@g++ -c ${SRC_DIR}CHanoiResolver.cpp -o ${OUTPUT_DIR}CHanoiResolver.o

board: ${SRC_DIR}CBoard.h ${SRC_DIR}CBoard.cpp 
	@echo "Compiling board..."
	@g++ -c ${SRC_DIR}CBoard.cpp -o ${OUTPUT_DIR}CBoard.o

tower: ${SRC_DIR}tower.h ${SRC_DIR}tower.cpp
	@echo "Compiling tower..."
	@g++ -c ${SRC_DIR}tower.cpp -o ${OUTPUT_DIR}tower.o

ring: ${SRC_DIR}ring.h ${SRC_DIR}ring.cpp
	@echo "Compiling ring..."
	@g++ -c ${SRC_DIR}ring.cpp -o ${OUTPUT_DIR}ring.o

clean:
	@echo "Cleaning objs files..."
	@rm -f ${OUTPUT_DIR}*.o
	@echo "Cleaning *.exe files..."
	@rm -f *.exe