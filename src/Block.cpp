#include "Block.hpp"

Block::Block(void)
{
}

int	Block::BlockType(glm::vec3 pos, float degrees)
{
	glm::vec3 newPos = glm::rotate(pos, glm::radians(-degrees), glm::vec3(0, 0, 1));

	int x = roundf(newPos.x);
	int y = roundf(newPos.y);

	if (x < -2 || x > 2 || y < -2 || y > 2)
		return -1;
	
	int index = (x + 2) + 5 * (y + 2);
	return _squares[index];
}

void	Block::Render(std::pair<glm::mat4, glm::mat4> perspective,
		      float degrees,
		      glm::vec3 pos)
{
	for (int y = -2; y <= 2; y++)
	{
		for (int x = -2; x <= 2; x++)
		{
			glm::vec3 blockPos(x, y, 0);

			blockPos = glm::rotate(blockPos, glm::radians(degrees), glm::vec3(0, 0, 1));

			int index = (x + 2) + (y + 2) * 5;
			
			int type = _squares[index];

			_models[type]->Render(perspective,
					      glm::rotate(glm::radians(degrees), glm::vec3(0, 0, 1)),
					      pos + blockPos);
		}
	}
}
