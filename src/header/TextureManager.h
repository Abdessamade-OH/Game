#pragma once
#include "gameHeader.h"

class TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* fileName);
};
