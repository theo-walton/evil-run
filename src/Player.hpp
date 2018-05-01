#pragma once

#include "game_core.hpp"
#include "Model.hpp"
#include "Window.hpp"

class	Player
{

	Model _model;
	double _dist;
	double _turnCooldown;

	void	LockToLane(double dt);
	void	SideMove(int dir);
	
public:

	glm::vec3 pos;
	glm::vec3 speed;
	glm::mat4 transform;

	Player(void);

	double	DistanceRun(void);
	glm::vec3	SteadyLocation(void);
	void	Update(Window& window, double dt);
	void	Render(std::pair<glm::mat4, glm::mat4> perspective);
};
