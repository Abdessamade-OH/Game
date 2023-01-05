#pragma once
#include "gameHeader.h"
#include "GameObject.h"
#include "fireBall.h"
#include "menuItem.h"
#include "scene.h"
#include "player.h"
#include "fireBall.h"
#include <vector>
#include <map>

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
		void addfireWall(GameObject* fireWall);
		void addfireBall(GameObject* fireBall);
		void addPlayer(Player* player, bool selected);
		void addKey(GameObject* key);
		void addDoor(GameObject* door);
		void addButton(GameObject* button);
		void setLevel(GameScene level);
	
	private:
		MenuItem* LevelbackButton = nullptr;
		MenuItem* successButton = nullptr;
		MenuItem* lossButton = nullptr;
		MenuItem* firstPlayerButton = nullptr;
		MenuItem* secondPlayerButton = nullptr;
		
		std::vector<Player*> players;

		std::vector<GameObject*> platforms;
		std::vector<GameObject*> spikes;
		std::vector<GameObject*> fireWalls;
		std::vector<GameObject*> fireBalls;

		
		std::map<int, GameObject*> buttons;
		
		std::vector<Player*>::iterator playerItr;
		std::vector<GameObject*>::iterator it;
		//std::vector<FireBall*>::iterator itr;
		
		bool unlocked = false;
		GameObject* key = nullptr;
		GameObject* door = nullptr;
		GameObject* button = nullptr;
		int success = 0;
		int counter = 0;
		bool isOver = false;
		bool buttonDown = false;
		
		GameScene selectedLevel;
		
		/*SDL_AudioSpec wavSpec;
		Uint32 wavLength;
		Uint8 *wavBuffer;
		
		SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);*/
};
