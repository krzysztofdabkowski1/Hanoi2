#include "ring.h"

Ring::Ring(unsigned int _size)
{
	size = _size;
	
	if(_size % 2 == 1)
	{
		color = Color::White;
	}
	else
	{
		color = Color::Black;
	}
};
	
Color Ring::getColor()
{
	return color;
};

unsigned int Ring::getSize()
{
	return size;
};