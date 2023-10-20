#include <iostream>
// #include "CBoard.h"
#include "CHanoiResolver.h"
#include "CGame.h"
#include <map>

class IAlgorithmResolver;

int main()
{
	IAlgorithmResolver* resolver = new HanoiResolver();
	Board board(4, 9, resolver);
	Game game(&board);
	game.run();
	return 0;
}