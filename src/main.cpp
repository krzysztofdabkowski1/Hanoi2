#include <iostream>
#include "CHanoiResolver.h"
#include "CGame.h"


class IAlgorithmResolver;

int main()
{
	IAlgorithmResolver* resolver = new HanoiResolver();
	Board board(4, 3, resolver, 3);
	Game game(&board);
	game.run();
	return 0;
}
