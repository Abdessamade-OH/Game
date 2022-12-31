#pragma once
#include "gameHeader.h"
#include "TextureManager.h"
#include "menuItem.h"

class Scene {

	public:
		Scene();
		~Scene();
		
		void init(const char* filename, int which);
		virtual void update() =0;
		virtual void render()=0;
		virtual void handleEvents();
		virtual void clean(){}
		bool running(){return isRunning;}
		GameScene getSelectedScene(){return selectedScene;}
		static SDL_Texture* textureSheet;
	protected:
		int which = 1;
		SDL_Texture* backgroundImage;
		bool isRunning;
		GameScene selectedScene;
};
