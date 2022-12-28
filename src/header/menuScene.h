#pragma once
#include "gameHeader.h"
#include <vector>

class MenuScene {

	public:
		MenuScene();
		~MenuScene();
		
		void init();
		void update();
		void render();
		void handleEvents(); 
		//int selected(){return selected}//returns selected scene
		void clean();
		bool running(){return isRunning;}
	
	private:
		SDL_Texture* backgroundImage;
		//vector<MenuItem> menuItems;
		bool isRunning;
		//int selected;
};
