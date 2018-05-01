#include "Map.hpp"

Land	Map::NewLand(void)
{
	Land& end = _path[_path.size() - 1];
	glm::vec3 newPos = end.Pos() + glm::rotate(glm::vec3(5, 0, 0),
						   glm::radians(end.Orientation()),
						   glm::vec3(0, 0, 1));

	Block* type;

	if (_straightCount < 5)
	{
		type = _straightBlock;
		_straightCount++;
	}
	else
	{
		float x = glm::linearRand(0.0f, 1.0f);

		if (x < 0.1f)
		{
			type = _leftCornerBlock;
			_straightCount = 0;
		}
		else if (x < 0.2f)
		{
			type = _rightCornerBlock;
			_straightCount = 0;
		}
		else if (x < 0.3f)
		{
			type = _jumpBlock;
			_straightCount = 0;
		}
		else if (x < 0.4f)
		{
			type = _middleBlock;
			_straightCount = 0;
		}
		else if (x < 0.5f)
		{
			type = _sideBlock;
			_straightCount = 0;
		}
		else
		{
			type = _straightBlock;
			_straightCount++;
		}
	}

	return Land(type, end.Orientation(), newPos);
}

Map::Map(void)
{
	_leftCornerBlock = new LeftBlock;
	_rightCornerBlock = new RightBlock;
	_straightBlock = new StraightBlock;
	_jumpBlock = new JumpBlock;
	_middleBlock = new MiddleBlock;
	_sideBlock = new SideBlock;
	
	_straightCount = 0;

	_path.push_back(Land(_straightBlock, 0, glm::vec3(0, 0, 0)));
	for (int i = 0; i < 20; i++)
	{
		_path.push_back(NewLand());
	}
}


void	Map::UpdatePath(glm::vec3 pos)
{
	size_t i = 0;

	while (i < _path.size())
	{
		if (_path[i].BlockType(pos) != -1)
			break;
		i++;
	}
	if (i < 5)
		return;	
	_path.erase(_path.begin());
	_path.push_back(NewLand());
}

int	Map::BlockType(glm::vec3 pos)
{
	size_t i = 0;

	while (i < _path.size())
	{
		if (_path[i].BlockType(pos) != -1)
			break;
		i++;
	}
	if (i == _path.size())
		return -1;
	return _path[i].BlockType(pos);
}

int	Map::EventType(glm::vec3 pos)
{
	UpdatePath(pos);
	int type = BlockType(pos);

	if (pos.z >= 1 && type == 3)
		type = 0;
	return type;
}

void	Map::Render(std::pair<glm::mat4, glm::mat4> perspective)
{
	for (auto& land : _path)
		land.Render(perspective);
}
