#pragma once
#include "SDL_image.h"
#include <vector>

using namespace std;
namespace CoreLib 
{
	class GAnimator
	{
	public:
		GAnimator(SDL_Texture* loadedTexture);
		~GAnimator();
		vector<SDL_Rect*> SetFrames(int frames, int xTile, int yTile, int width, int height);
		void Render(SDL_Renderer* renderer,int x , int y,SDL_Rect* clip);
	private:
		SDL_Texture* texture;
		vector<SDL_Rect*> framesRect;
		int width;
		int height;

	};
}


