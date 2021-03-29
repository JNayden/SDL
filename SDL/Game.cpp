#include "Game.h"
Game::Game()
{
	//window = SDL_CreateWindow("WIndow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
															//800, 600, SDL_WINDOW_SHOWN);


}

void Game::init(const char* title, int height, int width, int xpos, int ypos, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialised" << std::endl;
		window = SDL_CreateWindow(title, height, width, xpos, ypos, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::HandlEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}
void Game::Update()
{
	cnt++;
	std::cout << cnt << std::endl;
}
void Game::Render()
{
	SDL_RenderClear(renderer);
	//this is where we would add stuff to render
}
void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game cleaned!" << std::endl;
}


Game::~Game()
{
	Clean();
}