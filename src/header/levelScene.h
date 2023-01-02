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
		void handleEvents(float deltaTime); 
		void clean();
		void addObstacle(GameObject *obstacle);
		void addPlayer(Player* player, bool selected);
		void addKey(GameObject* key);
		void addDoor(GameObject* door);
	
	private:
		std::vector<Player*> players;
		MenuItem* LevelbackButton = nullptr;
		MenuItem* successButton = nullptr;
		std::vector<GameObject*> obstacles;
		std::vector<Player*>::iterator playerItr;
		bool unlocked = false;
		GameObject* key = nullptr;
		GameObject* door = nullptr;
		int success = 0;
		int counter = 0;
};
