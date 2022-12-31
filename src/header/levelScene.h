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
		
		void update();
		void render();
		void handleEvents(float deltaTime); 
		void clean();
		void addObstacle(GameObject *obstacle);
		void addPlayer(Player* player){players.push_back(player);}
	
	private:
		std::vector<Player*> players;
		MenuItem* LevelbackButton = nullptr;
		std::vector<GameObject*> obstacles;
		std::vector<Player*>::iterator playerItr;
};
