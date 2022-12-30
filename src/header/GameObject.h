#pragma once

#include "gameHeader.h"

class GameObject{
	
	public:
		GameObject(/*const char* textureSheet,*/ int x, int y, int w, int h);
		~GameObject();
		
		virtual void update();
		virtual void render();
		void setSrcRect(int x, int y, int w, int h);
		SDL_Rect* getDestRect();
		virtual void clean();
		
	protected:
		int xpos;
		int ypos;
		
		//SDL_Texture* objectTexture = NULL;
		SDL_Rect srcRect, destRect;
};
