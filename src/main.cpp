#include <iostream>
#include "CGame.h"
#include "CHanoiResolver.h"

int main()
{
	IAlgorithmResolver* resolver = new HanoiResolver();
	Board board(4, 3, 3);
	Game game(&board, resolver);
	game.run();
	return 0;
}
