#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Game
{
public:

	Game();
	~Game();
	void run();

private:

	void processEvents(SDL_Event t_e);
	void update();
	void render();
	void rendererDraw();

	void cleanUp();

	bool m_gameIsRunning;

	const int WINDOW_WIDTH{ 640 };
	const int WINDOW_HEIGHT{ 480 };

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};