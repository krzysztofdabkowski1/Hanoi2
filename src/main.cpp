#include <iostream>
#include "CBoard.h"
#include "CHanoiResolver.h"
#include <map>

class IAlgorithmResolver;

int main()
{
	std::map<int, int> myMap;
	//if(myMap[0].IsEmpty())
	//	std::cout<<myMap[0];
	// Ring ring(1);
	// Ring ring2(5);
	// Ring ring3(6);
	// Ring ring4(7);
	// std::cout<<ring.getColor();
	// Tower tower;
	// tower.addRing(ring4);
	// tower.addRing(ring3);
	// tower.addRing(ring2);
	// tower.addRing(ring);
	// tower.popRing();
	// tower.popRing();
	IAlgorithmResolver* resolver = new HanoiResolver();
	Board board(3, 8, resolver);
	
	return 0;
}