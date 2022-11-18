#pragma once
#include <SDL_image.h>
namespace CoreLib
{
	class GRenderer
	{
	public:
		GRenderer(SDL_Window* window);
		void AssignTextures(SDL_Texture* texture );
		void Update();
		SDL_Renderer* GetRenderer();

	private :
		SDL_Renderer* renderer = NULL;
	};

}

