#include "Player.hpp"

Player::Player(void) : _model("assets/player.model")
{
	pos = glm::vec3(0, 0, 0);
	speed = glm::vec3(0, 1, 0);
	transform = glm::mat4(1);
	_dist = 0;
	_turnCooldown = 0;
}

void	Player::LockToLane(double dt)
{
	if (fabs(speed.y) > fabs(speed.x))
	{
		glm::vec3 target(roundf(pos.x) - pos.x, 0, 0);

		pos += target * dt;
	}
	else
	{
		glm::vec3 target(0, roundf(pos.y) - pos.y, 0);

		pos += target * dt;
	}
}

void	Player::SideMove(int dir)
{
	if (fabs(speed.y) > fabs(speed.x))
	{
		if (speed.y < 0)
			dir = -dir;
		int lane = roundf(100002 + pos.x);
		lane %= 5;

		if (lane + dir == 0 || lane + dir == 4)
			return;
		pos.x += dir;
	}
	else
	{
		if (speed.x > 0)
			dir = -dir;
		int lane = roundf(100002 + pos.y);
		lane %= 5;

		if (lane + dir == 0 || lane + dir == 4)
			return;
		pos.y += dir;
	}
}

glm::vec3	Player::SteadyLocation(void)
{
	glm::vec3 out;
	
	if (fabs(speed.y) > fabs(speed.x))
	{
		int lane = (int)roundf(100002 + pos.x) % 5;

		out = glm::vec3(2 - lane + roundf(pos.x), pos.y, 0);
	}
	else
	{
		int lane = (int)roundf(100002 + pos.y) % 5;

		out = glm::vec3(pos.x, 2 - lane + roundf(pos.y), 0);
	}
	return out;
}

double	Player::DistanceRun(void)
{
	return _dist;
}

void	Player::Update(Window& window, double dt)
{
	if (window.KeyPress('A') && _turnCooldown < 0)
	{
		speed = glm::rotate(speed, glm::radians(90.0f), glm::vec3(0, 0, 1));
		transform = glm::rotate(transform, glm::radians(90.0f), glm::vec3(0, 0, 1));
		_turnCooldown = 0.5;
	}
	if (window.KeyPress('D') && _turnCooldown < 0)
	{
		speed = glm::rotate(speed, glm::radians(-90.0f), glm::vec3(0, 0, 1));
		transform = glm::rotate(transform, glm::radians(-90.0f), glm::vec3(0, 0, 1));
		_turnCooldown = 0.5;
	}
	if (window.KeyPress(' ') && pos.z < 0.02)
	{
		speed.z += 10;
	}
	else if (pos.z < 0.02 && speed.z < 0)
	{
		pos.z = 0;
		speed.z = 0;
	}
	speed.z -= 20 * dt;
	pos += speed * dt;

	if (window.KeyPress(GLFW_KEY_LEFT))
	{
		SideMove(-1);
	}
	if (window.KeyPress(GLFW_KEY_RIGHT))
	{
		SideMove(1);
	}

	speed *= 1 + (dt * 0.01);
	_dist += glm::length(glm::vec2(speed.x, speed.y)) * dt;
	LockToLane(dt);
	_turnCooldown -= dt;
}

void	Player::Render(std::pair<glm::mat4, glm::mat4> perspective)
{
	_model.Render(perspective, this->transform, this->pos);
}
