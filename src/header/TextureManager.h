#pragma once
#include "scene.h"

class TextureManager {
	public:
		static SDL_Texture* LoadTexture(const char* fileName);
};
