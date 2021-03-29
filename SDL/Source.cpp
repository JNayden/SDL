#include <iostream>
#include "SDL.h"
#include "Game.h"

Game* game;

int main(int argc, char* argv[]) 
{
	//SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Window* initwindow = SDL_CreateWindow("Everything", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	//SDL_Renderer* renderer = SDL_CreateRenderer(initwindow, -1, 0);
	//
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer); 
	//SDL_Delay(3000);
	
	game = new Game();
	game->init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->Running())
	{
		game->HandlEvents();
		game->Update();
		game->Render();
		
		//handle any user input
		//update all objects for ex. position
		//render changes to display
		
	}
	game->Clean();
	//SDL_Delay(3000);
	return 0;
}