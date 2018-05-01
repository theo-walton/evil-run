#pragma once

#include "game_core.hpp"
#include "Model.hpp"


//      ^
//      | Y
//      |
//   1 1 1 1 1
//   0 0 0 0 0   X
//   0 0 0 0 0 _ _ >
//   0 0 0 0 0
//   1 1 1 1 1
//
//
//   1 = wall
//   0 = floor
//
//   centered at origin
//

class	Block
{
protected:
	
	int _squares[25];
	std::vector<Model*> _models;

public:

	Block(void);

	virtual float	Orientation(void) = 0;
	
	int	BlockType(glm::vec3 pos, float degrees);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective,
		       float degrees,
		       glm::vec3 pos);	
};
