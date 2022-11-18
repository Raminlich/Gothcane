#include "GAnimator.h"

CoreLib::GAnimator::GAnimator(SDL_Texture* loadedTexture) 
{
	texture = loadedTexture;
	width = 0;
	height = 0;

}

CoreLib::GAnimator::~GAnimator() 
{
	if (texture != NULL) 
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

std::vector<SDL_Rect*> CoreLib::GAnimator::SetFrames(int frames, int xTile, int yTile, int tileWidth, int tileHeight)
{
	framesRect.clear();
	framesRect.resize(frames);
	for (int i = 0; i < frames; i++)
	{
		framesRect[i] = new SDL_Rect;
		framesRect[i]->x = i * xTile;
		framesRect[i]->y = i * yTile;
		framesRect[i]->w = tileWidth;
		framesRect[i]->h = tileHeight;
	}
	return framesRect;
}

void CoreLib::GAnimator::Render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
	SDL_Rect quad = { x,y,width,height };

	if (clip != NULL) 
	{
		quad.w = clip->w * 2;
		quad.h = clip->h * 2;
	}

	SDL_RenderCopy(renderer, texture, clip, &quad );
}
