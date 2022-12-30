#include "./header/gameHeader.h"
#include "./header/menuScene.h"
#include "./header/levelScene.h"
#include "./header/GameObject.h"
#include "./header/menuItem.h"
#include "./header/scene.h"
#include "./header/TextureManager.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Game *game = NULL;

int main(int argc, char* argv[]){
	GameScene currentScene = MAINMENU;
	const int FPS = 60;
	const int frameDelay = 1000/FPS; //we get the delta time for 60 FPS in ms (that's why we multiply by a 1000)
	
	Uint32 frameStart;
	int frameTime;
	
	
	game = new Game();
	game->init("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);
	
	while(game->running()){
		
		
	
		switch(currentScene){ //current scene will be an enum with three possibilites {mainMenu, levelMenu, levels} 	
			case QUIT:
				game->setRunning(false);
				break;
			case MAINMENU:{
				MenuScene* mainMenu = new MenuScene();
				cout<<"Inside mainMenu"<<endl;
				mainMenu->init("assets/MenuImage.png", 1);
				Scene::textureSheet = TextureManager::LoadTexture("assets/Button.png");
				MenuItem *startButton = new MenuItem(true, "Start", "assets/pixel font-7.ttf", 310, 240, 32*3, 20*3);
				MenuItem *exitButton = new MenuItem(true, "Exit", "assets/pixel font-7.ttf", 310, 320, 32*3, 20*3);
				MenuItem *menuTitle = new MenuItem(false, "Doors", "assets/pixel font-7.ttf", 304, 100, 32*4, 20*4);
				menuTitle->setSrcRect(32, 0, 32, 20);
				startButton->setSrcRect(0, 0, 32, 20);
				exitButton->setSrcRect(0, 0, 32, 20);
				mainMenu->addItem(startButton);
				mainMenu->addItem(exitButton);
				mainMenu->addItem(menuTitle);
				while(mainMenu->running()){
					//we get the time at when the frame starts
					frameStart = SDL_GetTicks();
					mainMenu->render();
					mainMenu->handleEvents();
					mainMenu->update();
					
					//this allows us to know how much time all the treatments takes per frame.
					//we store the time a frame has taken in frameTime
					frameTime = SDL_GetTicks() - frameStart;
					
					//if the time between each frame is less than the time between each frame in a 60 FPS setting, then we delay it by the difference between them to cap it at 60FPS.
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
					int deltaTime = SDL_GetTicks() - frameStart;
					//cout<<deltaTime<<endl;
					
				}
				currentScene = mainMenu->getSelectedScene();
				mainMenu->clean();
				delete(mainMenu);
				mainMenu = nullptr;
				SDL_DestroyTexture(Scene::textureSheet);
				Scene::textureSheet = nullptr;
				}break;
			
			case LEVELMENU:{
					MenuScene* levelsMenu = new MenuScene();
					cout<<"Inside levelsMenu"<<endl;
					levelsMenu->init("assets/MenuImage.png", 2);
					Scene::textureSheet = TextureManager::LoadTexture("assets/Button.png");
					MenuItem *menuTitle = new MenuItem(false, "Levels", "assets/pixel font-7.ttf", 800/2 - (32*2), 100, 32*4, 20*4);
					
					MenuItem *firstLevelButton = new MenuItem(true, "1", "assets/pixel font-7.ttf", 800/3 - (32*2) , 100 + 32*4, 32*4, 20*4);
					
					MenuItem *secondLevelButton = new MenuItem(true, "2", "assets/pixel font-7.ttf",  800/2 - (32*2), 100 + 32*4, 32*4, 20*4);
					
					MenuItem *thirdLevelButton = new MenuItem(true, "3", "assets/pixel font-7.ttf",  800/2 - (32*2) + 32*4+ 5, 100 + 32*4 , 32*4, 20*4);
					
					MenuItem *backButton = new MenuItem(true, "Back", "assets/pixel font-7.ttf", 800/2 - (32*2), 100 + 32*4*2 + 20, 32*4, 20*4);
					
					menuTitle->setSrcRect(32, 0, 32, 20);
					firstLevelButton->setSrcRect(0, 0, 32, 20);
					secondLevelButton->setSrcRect(0, 0, 32, 20);
					thirdLevelButton->setSrcRect(0, 0, 32, 20);
					backButton->setSrcRect(32, 0, 32, 20);
					levelsMenu->addItem(menuTitle);
					levelsMenu->addItem(firstLevelButton);
					levelsMenu->addItem(secondLevelButton);
					levelsMenu->addItem(thirdLevelButton);
					levelsMenu->addItem(backButton);
					
					while(levelsMenu->running()){
						//we get the time at when the frame starts
						frameStart = SDL_GetTicks();
						levelsMenu->render();
						levelsMenu->handleEvents();
						levelsMenu->update();
						
						//this allows us to know how much time all the treatments takes per frame.
						//we store the time a frame has taken in frameTime
						frameTime = SDL_GetTicks() - frameStart;
						
						//if the time between each frame is less than the time between each frame in a 60 FPS setting, then we delay it by the difference between them to cap it at 60FPS.
						if(frameDelay>frameTime){
							SDL_Delay(frameDelay - frameTime);
						}
					
					int deltaTime = SDL_GetTicks() - frameStart;
					//cout<<deltaTime<<endl;
					
				}
				cout<<"leaving levelMenu"<<endl;
				currentScene = levelsMenu->getSelectedScene();
				levelsMenu->clean();
				delete(levelsMenu);
				levelsMenu = nullptr;
				SDL_DestroyTexture(Scene::textureSheet);
				Scene::textureSheet = nullptr;
				}break;
				
			case FIRSTLEVEL:{
				//int levelnum = levelMenu->selectedLevel;
				//level[levelnum]->init();
				LevelScene* firstLevel = new LevelScene();
				cout<<"inside first level."<<endl;
				Scene::textureSheet = TextureManager::LoadTexture("assets/Button.png");
				firstLevel->init("assets/levelBackGround.png", 1);
				
				while(firstLevel->running()){
					frameStart = SDL_GetTicks();
					
					firstLevel->update();
					firstLevel->render();
					firstLevel->handleEvents();
					
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
				}
				currentScene = firstLevel->getSelectedScene();
				firstLevel->clean();
				delete(firstLevel);
				firstLevel = nullptr;
				cout<<"FIRSTLEVEL out"<<endl;
				SDL_DestroyTexture(Scene::textureSheet);
				Scene::textureSheet = nullptr;
				}break;
				
			case SECONDLEVEL:{
				LevelScene* secondLevel = new LevelScene();
				cout<<"inside second level."<<endl;
				Scene::textureSheet = TextureManager::LoadTexture("assets/Button.png");
				secondLevel->init("assets/levelBackGround.png", 2);
				while(secondLevel->running()){
					frameStart = SDL_GetTicks();
					
					secondLevel->update();
					secondLevel->render();
					secondLevel->handleEvents();
					
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
				}
				currentScene = secondLevel->getSelectedScene();
				secondLevel->clean();
				delete(secondLevel);
				secondLevel = nullptr;
				cout<<"SECONDLEVEL out"<<endl;
				SDL_DestroyTexture(Scene::textureSheet);
				Scene::textureSheet = nullptr;
			}break;
			
			case THIRDLEVEL:{
				LevelScene* thirdLevel = new LevelScene();
				cout<<"inside third level."<<endl;
				Scene::textureSheet = TextureManager::LoadTexture("assets/Button.png");
				thirdLevel->init("assets/levelBackGround.png", 3);
				while(thirdLevel->running()){
					frameStart = SDL_GetTicks();
					
					thirdLevel->update();
					thirdLevel->render();
					thirdLevel->handleEvents();
					
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
				}
				currentScene = thirdLevel->getSelectedScene();
				thirdLevel->clean();
				delete(thirdLevel);
				thirdLevel = nullptr;
				cout<<"thirdLevel out"<<endl;
				cout<<"THIRDLEVEL"<<endl;
				SDL_DestroyTexture(Scene::textureSheet);
				Scene::textureSheet = nullptr;
			}break;
			
			
		}
		game->handleEvents();
		
	}
	
	game->clean();
	cout<<"Game cleared"<<endl;
	
	return 0;
}
