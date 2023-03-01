#include "UncoverEmpty.h"

UncoverEmpty::UncoverEmpty()
{
}

UncoverEmpty::~UncoverEmpty()
{
}

void UncoverEmpty::top(Cell* cells, short pos)
{
	if (cells[pos].getNumb() > 0)
	{
		cells[pos].setIsClick(true);
		return;
	}
	else
	{
		cells[pos].setIsClick(true);
	}
	pos -= 16;
	return top(cells, pos);
}

void UncoverEmpty::upperRight(Cell* cells, short pos)
{
}

void UncoverEmpty::right(Cell* cells, short pos)
{
}

void UncoverEmpty::lowerRight(Cell* cells, short pos)
{
}

void UncoverEmpty::buttom(Cell* cells, short pos)
{
	if (cells[pos].getNumb() > 0)
	{
		cells[pos].setIsClick(true);
		return;
	}
	else
	{
		cells[pos].setIsClick(true);
	}
	pos += 16;
	return buttom(cells, pos);
}

void UncoverEmpty::lowerLeft(Cell* cells, short pos)
{
}

void UncoverEmpty::left(Cell* cells, short pos)
{
}

void UncoverEmpty::upperLeft(Cell* cells, short pos)
{
}
