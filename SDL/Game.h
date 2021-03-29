#pragma once
#include "SDL.h"
#include <iostream>
class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int height, int width, int xpos, int ypos, bool fullscreen);

	void HandlEvents();
	void Update();
	void Render();
	void Clean();

	bool Running() { return isRunning; }
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int cnt = 0;
};

