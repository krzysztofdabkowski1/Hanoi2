#include "CRing.h"
#include <iostream>

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

Ring::~Ring()
{
    std::cout<<"Deleting Ring:"<<size<<std::endl;	
}
	
Color Ring::getColor()
{
	return color;
};

unsigned int Ring::getSize()
{
	return size;
};