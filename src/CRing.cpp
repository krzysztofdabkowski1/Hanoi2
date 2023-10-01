#include "CRing.h"
#include <iostream>

CRing::CRing(unsigned int _size)
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

CRing::~CRing()
{
    std::cout<<"Deleting Ring:"<<size<<std::endl;	
}
	
Color CRing::getColor()
{
	return color;
};

unsigned int CRing::getSize()
{
	return size;
};