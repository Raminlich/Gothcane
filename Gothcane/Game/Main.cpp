#include "GResourceManager.h"
#include "GRenderer.h"
#include <SDL_image.h>
#include <iostream>
using namespace CoreLib;
using namespace std;
SDL_Window* window = NULL;
const int WINDOW_W = 800;
const int WINDOW_H = 600;
bool quit;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not be initialiazed! ", SDL_GetError();
	}
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		cout << "IMG could not be initialiazed! ", SDL_GetError();
		return 1;
	}
	window = SDL_CreateWindow("Gothcane", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());

		return 1;
	}
	SDL_Rect* rect = new SDL_Rect();
	rect->x = 0;
	rect->y = 0;
	rect->w = 0;
	rect->h = 0;
	GRenderer* renderer = new GRenderer(window);
	GResourceManager* rscm = new GResourceManager();
	SDL_Texture* texture = NULL;
	SDL_Texture* anotherTexture = NULL;
	texture = rscm->LoadTexture("C:/Users/Ramin/Documents/Repos/Gothcane/castle.png",renderer->GetRenderer());
	anotherTexture = rscm->LoadTexture("C:/Users/Ramin/Documents/Repos/Gothcane/idle.png", renderer->GetRenderer());

	SDL_Event sdlEvent;
	while (!quit)
	{
		while (SDL_PollEvent(&sdlEvent) != 0)
		{
			if (sdlEvent.type == SDL_QUIT)
			{
				SDL_Quit();
			}
		}
		SDL_RenderClear(renderer->GetRenderer());
		SDL_RenderCopy(renderer->GetRenderer(), texture, NULL, NULL);
		SDL_RenderCopy(renderer->GetRenderer(), anotherTexture, rect, rect+2);
		SDL_RenderPresent(renderer->GetRenderer());
	}

	return 0;
}