#ifndef CRing_H
#define CRing_H

enum Color
{
	White = 1,
	Black = 2
};

class CRing
{

  public:
	CRing(unsigned int _size);
	~CRing();
	Color getColor();
	unsigned int getSize();
	inline bool isGreaterThan(CRing *_ring)
	{
		return _ring->size > size;
	}

  private:
	Color color;
	unsigned int size;
};
#endif