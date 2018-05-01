#pragma once

#include "IState.hpp"
#include "Engine.hpp"
#include "game_core.hpp"
#include "Camera.hpp"
#include "Player.hpp"
#include "Light.hpp"
#include "Map.hpp"
#include "Block.hpp"
#include "Text.hpp"
#include "Sprite2D.hpp"

class	RunState : public IState
{

	Player _player;
	Map _map;
	Camera _camera;
	Engine& _engine;
	Sprite2D _skull;
	bool _dead;
	glm::vec3 _lightCol;
	
public:

	RunState(Engine& e);

	void	Update(double dt);
};
