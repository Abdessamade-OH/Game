#pragma once

#include "gameHeader.h"
#include <vector>

class GameObject{
	
	public:
		GameObject(/*const char* textureSheet,*/ float x, float y, int w, int h);
		~GameObject();
		
		virtual void update();
		virtual void render();
		void setSrcRect(int x, int y, int w, int h);
		SDL_FRect* getDestRect();
		virtual void clean();
		//std::vector<int> getPos();
		
	protected:
		
		//SDL_Texture* objectTexture = NULL;
		SDL_Rect srcRect;
		SDL_FRect destRect;
};
