#include "Game.h"

Game::Game() :
	m_gameIsRunning{ false }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow("FSM",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								WINDOW_WIDTH,
								WINDOW_HEIGHT,
								SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window,
									-1,
									SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
}

Game::~Game()
{
	cleanUp();
}

void Game::run()
{	
	m_gameIsRunning = true;
	SDL_Event e{};

	while (m_gameIsRunning)
	{
		processEvents(e);
		update();
		render();
	}

	cleanUp();
}

void Game::processEvents(SDL_Event t_e)
{
	// simple event loop
	while (SDL_PollEvent(&t_e) != 0)
	{
		if (t_e.type == SDL_QUIT)
		{
			m_gameIsRunning = false;
		}

		// checks if the escape key is pressed down
		if (t_e.type == SDL_KEYDOWN && t_e.key.keysym.sym == SDLK_ESCAPE)
		{
			m_gameIsRunning = false;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	rendererDraw();
}

void Game::rendererDraw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0);
	SDL_RenderClear(m_renderer);

	SDL_FRect renderSrc{ 0, 0, 0, 0 };
	SDL_FRect renderDest{ 5, 5, 200, 100 };

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderPresent(m_renderer);
}

void Game::cleanUp()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	m_renderer = nullptr;

	SDL_Quit();
}