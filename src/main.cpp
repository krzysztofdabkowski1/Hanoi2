#include <iostream>
// #include "CBoard.h"
#include "CHanoiResolver.h"
#include "CMoveReader.h"
#include <map>

class IAlgorithmResolver;

int main()
{
	IAlgorithmResolver* resolver = new HanoiResolver();
	Board board(4, 9, resolver);
	MoveReader reader(&board);
	reader.read();
	return 0;
}