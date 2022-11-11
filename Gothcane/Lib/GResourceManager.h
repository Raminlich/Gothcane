#pragma once
#include <SDL_image.h>
#include <iostream>
namespace CoreLib {

	class GResourceManager
	{
	public :
		SDL_Texture* LoadTexture(std::string path , SDL_Renderer* renderer);
	private:
		void ShowError();
	};

}


