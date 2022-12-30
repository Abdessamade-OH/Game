#pragma once
#include "gameHeader.h"
#include "GameObject.h"
#include "menuItem.h"
#include "scene.h"
#include <vector>

class LevelScene : public Scene{
	public:
		LevelScene();
		~LevelScene();
		
		void update();
		void render();
		void handleEvents(); 
		void clean();
		void addObstacle(GameObject *obstacle);
		
	
	private:
		//MenuItem* backButton = nullptr;
		std::vector<GameObject*> obstacles;
};
