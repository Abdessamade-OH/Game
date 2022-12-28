#pragma once

#include "scene.h"

class GameObject{
	
	public:
		GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y, int h, int w);
		~GameObject();
		
		void update();
		void render();
		void setSrcRect(int x, int y, int h, int w);
		SDL_Rect* getDestRect();
		
	protected:
		int xpos;
		int ypos;
		
		SDL_Texture* objectTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;
};
