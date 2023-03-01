#pragma once
#include "Cell.h"
class UncoverEmpty
{
public:
	// Contructor / Desctructor
	UncoverEmpty(Cell* cells, short pos);
	~UncoverEmpty();

	// Methods
	void top(Cell* cells, short pos);
	void upperRight(Cell* cells, short pos);
	void right(Cell* cells, short pos);
	void lowerRight(Cell* cells, short pos);
	void buttom(Cell* cells, short pos);
	void lowerLeft(Cell* cells, short pos);
	void left(Cell* cells, short pos);
	void upperLeft(Cell* cells, short pos);
};