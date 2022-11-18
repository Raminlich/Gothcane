#include "GRenderer.h"
#include <iostream>
#include <vector>

CoreLib::GRenderer::GRenderer(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "Renderer could not be created! ", SDL_GetError();
		throw "Renderer problem";
	}
	else
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}


void CoreLib::GRenderer::Update(SDL_Texture* texture)
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void CoreLib::GRenderer::Update(std::vector<SDL_Texture*> textures)
{
	SDL_RenderClear(renderer);
	for (auto texture : textures)
	{
		SDL_RenderCopy(renderer, texture, NULL, NULL);
	}
	SDL_RenderPresent(renderer);
}

SDL_Renderer* CoreLib::GRenderer::GetRenderer()
{
	return renderer;
}
