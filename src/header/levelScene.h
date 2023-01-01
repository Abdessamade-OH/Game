#pragma once
#include "gameHeader.h"
#include "GameObject.h"
#include "menuItem.h"
#include "scene.h"
#include "player.h"
#include <vector>

class LevelScene : public Scene{
	public:
		LevelScene();
		~LevelScene();
		
		void update(double deltaTime);
		void render();
		void handleEvents(double deltaTime); 
		void clean();
		void addObstacle(GameObject *obstacle);
		void addPlayer(Player* player, bool selected);
	
	private:
		std::vector<Player*> players;
		MenuItem* LevelbackButton = nullptr;
		std::vector<GameObject*> obstacles;
		std::vector<Player*>::iterator playerItr;
};
