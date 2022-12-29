#pragma once
#include "gameHeader.h"
#include "menuItem.h"
#include "GameObject.h"
#include <vector>

class MenuScene {

	public:
		MenuScene();
		~MenuScene();
		
		void init(const char* filename, int whichMenu);
		void update();
		void render();
		void handleEvents(); 
		//int selected(){return selected}//returns selected scene
		void clean();
		bool running(){return isRunning;}
		GameScene getSelected(){return selected;}
		void addItem(MenuItem *item);
		
		//void setMenuItem(int index, )
	
	private:
		int whichMenu = 0;
		SDL_Texture* backgroundImage;
		std::vector<MenuItem*> items;
		bool isRunning;
		GameScene selected;
};
