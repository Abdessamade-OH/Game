#pragma once
#include "gameHeader.h"
#include "GameObject.h"
#include <SDL2/SDL_ttf.h>

class MenuItem : public GameObject{
	private:
		bool button;
		bool selected = false;
		SDL_Surface* textSurface = NULL;
		SDL_Texture* textTexture = NULL;
		const char* text;
		TTF_Font* font = NULL;
		SDL_Color textColor[2] = {{0, 0, 0}, {238, 130, 238}};
		SDL_Rect textRect = (SDL_Rect){destRect.x + 5, destRect.y + 5, destRect.w - 10, destRect.h - 10};
	public:
		~MenuItem();
		MenuItem(bool buttonState, const char* text, const char* fontFile, const char* textureSheet, int x, int y, int w, int h);


		bool getButtonState(){return this->button;}
		bool getSelected(){return this->selected;}
		void setSelected(bool state);
		void clean();
		void render();
		void update();
};
