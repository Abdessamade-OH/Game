#include "./header/gameHeader.h"
#include "./header/menuScene.h"
#include "./header/GameObject.h"
#include "./header/menuItem.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Game *game = NULL;

int main(int argc, char* argv[]){
	GameScene currentScene = MAINMENU;
	const int FPS = 30;
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
				MenuItem *startButton = new MenuItem(true, "Start", "assets/pixel font-7.ttf","assets/Button.png", 310, 240, 32*3, 20*3);
				MenuItem *exitButton = new MenuItem(true, "Exit", "assets/pixel font-7.ttf", "assets/Button.png", 310, 320, 32*3, 20*3);
				MenuItem *menuTitle = new MenuItem(false, "Doors", "assets/pixel font-7.ttf", "assets/Button.png", 304, 100, 32*4, 20*4);
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
				currentScene = mainMenu->getSelected();
				mainMenu->clean();
				delete(mainMenu);
				mainMenu = nullptr;
				}break;
			
			case LEVELMENU:{
					MenuScene* levelsMenu = new MenuScene();
					cout<<"Inside levelsMenu"<<endl;
					levelsMenu->init("assets/MenuImage.png", 2);
					
					MenuItem *menuTitle = new MenuItem(false, "Levels", "assets/pixel font-7.ttf", "assets/Button.png", 800/2 - (32*2), 100, 32*4, 20*4);
					
					MenuItem *firstLevel = new MenuItem(true, "1", "assets/pixel font-7.ttf", "assets/Button.png", 800/3 - (32*2) , 100 + 32*4, 32*4, 20*4);
					
					MenuItem *secondLevel = new MenuItem(true, "2", "assets/pixel font-7.ttf", "assets/Button.png", 800/2 - (32*2), 100 + 32*4, 32*4, 20*4);
					
					MenuItem *thirdLevel = new MenuItem(true, "3", "assets/pixel font-7.ttf", "assets/Button.png", 800/2 - (32*2) + 32*4+ 5, 100 + 32*4 , 32*4, 20*4);
					
					MenuItem *back = new MenuItem(true, "Back", "assets/pixel font-7.ttf", "assets/Button.png", 800/2 - (32*2), 100 + 32*4*2 + 20, 32*4, 20*4);
					
					menuTitle->setSrcRect(32, 0, 32, 20);
					firstLevel->setSrcRect(0, 0, 32, 20);
					secondLevel->setSrcRect(0, 0, 32, 20);
					thirdLevel->setSrcRect(0, 0, 32, 20);
					back->setSrcRect(32, 0, 32, 20);
					levelsMenu->addItem(menuTitle);
					levelsMenu->addItem(firstLevel);
					levelsMenu->addItem(secondLevel);
					levelsMenu->addItem(thirdLevel);
					levelsMenu->addItem(back);
					
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
				currentScene = levelsMenu->getSelected();
				levelsMenu->clean();
				delete(levelsMenu);
				levelsMenu = nullptr;
				}break;
				
			case FIRSTLEVEL:
				//int levelnum = levelMenu->selectedLevel;
				//level[levelnum]->init();
				cout<<"FIRSTLEVEL"<<endl;
				break;
			case SECONDLEVEL:
				cout<<"SECONDLEVEL"<<endl;
			break;
			case THIRDLEVEL:
				cout<<"THIRDLEVEL"<<endl;
			break;
			
			
		}
		game->handleEvents();
		
	}
	
	game->clean();
	cout<<"Game cleared"<<endl;
	
	return 0;
}
