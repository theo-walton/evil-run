#include "RunState.hpp"

RunState::RunState(Engine& e) : _engine(e),
				_skull("assets/textures/skull.png")
{
	_player.speed = glm::vec3(7, 0, 0);
	glClearColor(0.1, 0, 0, 0);
	_lightCol = glm::vec3(1, 1, 1);
	_dead = false;
}

void	RunState::Update(double dt)
{
	glm::vec3 lightPos = _player.SteadyLocation();
	lightPos.z = _player.pos.z + 2;
	Light l(glm::vec3(lightPos), _lightCol, 10);

	if (_dead)
	{
		_lightCol /= (1 + dt * 2);
	}
	
	if (!_dead)
	{
		_player.Update(_engine.window, dt);
	
		glm::vec3 target = _player.SteadyLocation() -		
			glm::normalize(glm::vec3(_player.speed.x, _player.speed.y, 0)) * 8 +
				       glm::vec3(0, 0, 7);

		_camera.Move((target - _camera.GetPosition()) * std::min(dt, 0.5) * 5);
		_camera.SetAspect(_engine.window.GetAspect());
	}

	glm::vec3 lookat_target = _player.SteadyLocation() + glm::vec3(0, 0, 3);

	int event = _map.EventType(_player.pos);

	if (event)
	{
		_dead = true;
	}

	_player.Render(_camera.Perspective(lookat_target));
	_map.Render(_camera.Perspective(lookat_target));

	std::stringstream ss;
	ss << "Distance: " << std::fixed << std::setprecision(4) << _player.DistanceRun();
	Text score(ss.str());


	_engine.window.SetRenderMask(0.4 * _lightCol.x, 0.9 * _lightCol.y,
				     0.2 + 0.8 * (1 - _lightCol.x),
				     0.1 + 0.8 * (1 - _lightCol.x));
	score.Render(_engine.window.GetAspect());
	_engine.window.RemoveRenderMask();

	if (_dead)
		_skull.Render();
}
