#include "Land.hpp"

Land::Land(Block* block, float degrees, glm::vec3 pos) : _block(block),
							 _degrees(degrees),
							 _pos(pos)
{
}

float	Land::Orientation(void)
{
	return _block->Orientation() + _degrees;
}

glm::vec3	Land::Pos(void)
{
	return _pos;
}

void	Land::Render(std::pair<glm::mat4, glm::mat4> perspective)
{
	_block->Render(perspective, _degrees, _pos);
}

int	Land::BlockType(glm::vec3 pos)
{
	return _block->BlockType(pos - _pos, _degrees);
}
