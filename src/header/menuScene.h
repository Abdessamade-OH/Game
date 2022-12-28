#pragma once
#include "gameHeader.h"
//#include "menuItem.h"
#include "GameObject.h"
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
		void addItem(GameObject *item);
		
		//void setMenuItem(int index, )
	
	private:
		SDL_Texture* backgroundImage;
		std::vector<GameObject*> items;
		bool isRunning;
		GameScene selected;
};
