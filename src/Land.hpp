#pragma once

#include "Block.hpp"
#include "game_core.hpp"

class	Land
{
	Block *_block;
	float _degrees; // orientation amount in degrees
	glm::vec3 _pos;

public:

	Land(Block*, float degrees, glm::vec3 pos);

	float Orientation(void); // returns the orientation required to connect with this block in degrees
	glm::vec3 Pos(void);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective);
	int	BlockType(glm::vec3 pos); // -1 if pos is not on land region
};
