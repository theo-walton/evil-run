#include "JumpBlock.hpp"

JumpBlock::JumpBlock(void)
{
	_squares[20] = 1; _squares[21] = 1; _squares[22] = 1; _squares[23] = 1; _squares[24] = 1;
	_squares[15] = 0; _squares[16] = 0; _squares[17] = 3; _squares[18] = 0; _squares[19] = 0;
	_squares[10] = 0; _squares[11] = 0; _squares[12] = 3; _squares[13] = 0; _squares[14] = 0;
	_squares[5]  = 0; _squares[6]  = 0; _squares[7]  = 3; _squares[8]  = 0; _squares[9]  = 0;
	_squares[0]  = 1; _squares[1]  = 1; _squares[2]  = 1; _squares[3]  = 1; _squares[4]  = 1;

	_models.push_back(new Model("assets/floor.model"));
	_models.push_back(new Model("assets/crate.model"));
	_models.push_back(new Model("assets/block.model"));
	_models.push_back(new Model("assets/rock.model"));
}

float	JumpBlock::Orientation(void)
{
	return 0;
}
