#pragma once

#include "Land.hpp"
#include "Block.hpp"
#include "game_core.hpp"
#include "StraightBlock.hpp"
#include "LeftBlock.hpp"
#include "RightBlock.hpp"
#include "JumpBlock.hpp"
#include "MiddleBlock.hpp"
#include "SideBlock.hpp"

class	Map
{

	std::vector<Land> _path;
	Block *_straightBlock;
	Block *_leftCornerBlock;
	Block *_rightCornerBlock;

	//event blocks
	Block *_jumpBlock;
	Block *_middleBlock;
	Block *_sideBlock;
	
	int _straightCount;

	Land	NewLand(void);
        void    UpdatePath(glm::vec3 pos);
        int     BlockType(glm::vec3 pos);
	
public:


	Map(void);

	int	EventType(glm::vec3 pos);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective);
};
