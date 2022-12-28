#pragma once
#include "gameHeader.h"
#include <vector>

class MenuScene {

	public:
		MenuScene();
		~MenuScene();
		
		void init(const char* filename);
		void update();
		void render();
		void handleEvents(); 
		//int selected(){return selected}//returns selected scene
		void clean();
		bool running(){return isRunning;}
		GameScene getSelected(){return selected;}
	
	private:
		SDL_Texture* backgroundImage;
		//vector<MenuItem> menuItems;
		bool isRunning;
		GameScene selected;
};
