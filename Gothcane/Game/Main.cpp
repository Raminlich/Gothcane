/*
 ------------------------------------------------------------------------------------------------
This file is only temporary and for the purpose of testing other library modules
-------------------------------------------------------------------------------------------------
*/


#include "GResourceManager.h"
#include "GRenderer.h"
#include "GAnimator.h"
#include <SDL_image.h>
#include <iostream>
#include <vector>
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



	GRenderer* renderer = new GRenderer(window);
	GResourceManager* rscm = new GResourceManager();
	SDL_Texture* spriteSheet = NULL;
	spriteSheet = rscm->LoadTexture("Pyromancer_Idle.png", renderer->GetRenderer());
	GAnimator* animator = new GAnimator(spriteSheet);
	auto frameContainer = animator->SetFrames(8, 150, 0, 150, 150);
	SDL_Event sdlEvent;
	int frame = 0;
	int timeFrame = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&sdlEvent) != 0)
		{
			if (sdlEvent.type == SDL_QUIT)
			{
				SDL_Quit();
			}
		}

		if (timeFrame > 300000) 
		{
			SDL_SetRenderDrawColor(renderer->GetRenderer(), 0, 0, 0, 0);
			SDL_RenderClear(renderer->GetRenderer());
			SDL_Rect* currentClip = frameContainer[frame];
			animator->Render(renderer->GetRenderer(), 250, 150, currentClip);
			++frame;
			if (frame > 7)
			{
				frame = 0;
			}
			SDL_RenderPresent(renderer->GetRenderer());
			timeFrame = 0;
		}
		timeFrame++;

	}

	return 0;
}