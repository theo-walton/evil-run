
#include "Window.hpp"
#include "RunState.hpp"
#include "Engine.hpp"
#include "game_core.hpp"

int	main(void)
{
	Window window(1600, 900, "bomberman");
	Engine engine(window);
	engine.PushState(new RunState(engine));
	while (engine.isRunning)
	{
		engine.Run();
	}
	return 0;
}
