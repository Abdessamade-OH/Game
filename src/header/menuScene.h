#pragma once
#include "gameHeader.h"
#include "menuItem.h"
#include "GameObject.h"
#include "scene.h"
#include <vector>

class MenuScene : public Scene{

	public:
		MenuScene();
		~MenuScene();
		
		//void init(const char* filename, int which);
		void update();
		void render();
		void handleEvents(); 
		//int selected(){return selected}//returns selected scene
		void clean();
		//bool running(){return isRunning;}
		//GameScene getSelectedScene(){return selectedScene;}
		void addItem(MenuItem *item);
		static SDL_Texture* menuTexture;
		//void setMenuItem(int index, )
	
	private:
		//int which = 0;
		//SDL_Texture* backgroundImage;
		std::vector<MenuItem*> items;
		
};
