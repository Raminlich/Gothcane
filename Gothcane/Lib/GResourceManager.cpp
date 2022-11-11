#include "GResourceManager.h"
#include <iostream>

using namespace std;
using namespace CoreLib;

SDL_Texture* GResourceManager::LoadTexture(string path , SDL_Renderer* renderer)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* textureSurface = IMG_Load(path.c_str());
	if (textureSurface == NULL)
	{
		SDL_LogError(0,IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
		if (texture == NULL)
		{
			SDL_LogError(0, IMG_GetError());
		}
		SDL_FreeSurface(textureSurface);
	}
	return texture;
}
