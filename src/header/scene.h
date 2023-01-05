#pragma once
#include "gameHeader.h"
#include "TextureManager.h"
#include "menuItem.h"

class Scene {

	public:
		Scene();
		~Scene();
		
		void init(const char* filename, int which);
		
		bool running(){return isRunning;}
		GameScene getSelectedScene(){return selectedScene;}
		static SDL_Texture* textureSheet;
	protected:
		int which = 1;
		SDL_Texture* backgroundImage;
		bool isRunning;
		GameScene selectedScene;
};
