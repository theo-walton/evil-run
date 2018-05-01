#include "StraightBlock.hpp"

StraightBlock::StraightBlock(void)
{
	for (int i = 0; i < 25; i++)
	{
		if (i < 5 || i >= 20)
			_squares[i] = 1;
		else
			_squares[i] = 0;
	}
	_models.push_back(new Model("assets/floor.model"));
	_models.push_back(new Model("assets/crate.model"));
}

float	StraightBlock::Orientation(void)
{
	return 0;
}
