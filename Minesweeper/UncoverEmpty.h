#pragma once
class UncoverEmpty
{
public:
	// Contructor / Desctructor
	UncoverEmpty(short& cells, short pos);
	~UncoverEmpty();

	// Methods
	void top(short& cells, short pos);
	void upperRight(short& cells, short pos);
	void right(short& cells, short pos);
	void lowerRight(short& cells, short pos);
	void buttom(short& cells, short pos);
	void lowerLeft(short& cells, short pos);
	void left(short& cells, short pos);
	void upperLeft(short& cells, short pos);
};