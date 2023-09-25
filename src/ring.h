enum Color
{
	White = 1,
	Black = 2
};

class Ring
{

  public:
	Ring(unsigned int _size);
	Color getColor();
	unsigned int getSize();
	inline bool isGreaterThan(Ring _ring)
	{
		return _ring.size > size;
	}

  private:
	Color color;
	unsigned int size;
};