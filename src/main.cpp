#include <iostream>
#include "CGame.h"
#include "CHanoiResolver.h"

int main()
{
	const int TOWER_NUMBER = 3;
	const int RINGS_NUMBER = 8;
	const int FINAL_TOWER  = 3;

	IAlgorithmResolver* resolver = new HanoiResolver();
	Board* board = new Board(TOWER_NUMBER, RINGS_NUMBER, FINAL_TOWER);
	Game game(board, resolver);
	game.run();
	return 0;
}
