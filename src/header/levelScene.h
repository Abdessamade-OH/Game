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
		
		void update(float deltaTime);
		void render();
		void handleEvents(); 
		void clean();
		void addObstacle(GameObject *obstacle);
		void addPlayer(Player* player){players.push_back(player);}
	
	private:
		std::vector<Player*> players;
		MenuItem* LevelbackButton = nullptr;
		std::vector<GameObject*> obstacles;
};
