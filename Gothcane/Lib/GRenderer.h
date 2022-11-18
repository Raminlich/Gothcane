#pragma once
#include <SDL_image.h>
#include <vector>

using namespace std;
namespace CoreLib
{
	class GRenderer
	{
	public:
		GRenderer(SDL_Window* window);
		void Update(SDL_Texture* texture);
		void Update(vector<SDL_Texture*> textures);
		SDL_Renderer* GetRenderer();

	private :
		SDL_Renderer* renderer = NULL;
	};

}

