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
		void addPlatform(GameObject *platform);
		void addSpike(GameObject *spike);
		void addPlayer(Player* player, bool selected);
		void addKey(GameObject* key);
		void addDoor(GameObject* door);
	
	private:
		MenuItem* LevelbackButton = nullptr;
		MenuItem* successButton = nullptr;
		MenuItem* lossButton = nullptr;
		MenuItem* firstPlayerButton = nullptr;
		MenuItem* secondPlayerButton = nullptr;
		
		std::vector<Player*> players;

		std::vector<GameObject*> platforms;
		std::vector<GameObject*> spikes;
		
		std::vector<Player*>::iterator playerItr;
		std::vector<GameObject*>::iterator it;
		
		bool unlocked = false;
		GameObject* key = nullptr;
		GameObject* door = nullptr;
		int success = 0;
		int counter = 0;
		bool isOver = false;
};
