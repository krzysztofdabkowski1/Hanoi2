#include <iostream>
#include "CGame.h"
#include "CHanoiResolver.h"


int main()
{
	IAlgorithmResolver* resolver = new HanoiResolver();
	Board board(4, 3, resolver, 3);
	Game game(&board);
	game.run();
	return 0;
}
