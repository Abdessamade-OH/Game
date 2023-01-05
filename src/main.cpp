#include "./header/gameHeader.h"
#include "./header/menuScene.h"
#include "./header/levelScene.h"
#include "./header/GameObject.h"
#include "./header/fireBall.h"
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
	float deltaTime = 0;
	Scene::textureSheet = TextureManager::LoadTexture("assets/textureSheet.png");
	while(game->running()){
		
		
	
		switch(currentScene){ //current scene will be an enum with three possibilites {mainMenu, levelMenu, levels} 	
			case QUIT:
				game->setRunning(false);
				break;
			case MAINMENU:{
				MenuScene* mainMenu = new MenuScene();
				cout<<"Inside mainMenu"<<endl;
				mainMenu->init("assets/MenuImage.png", 1);
				MenuItem *startButton = new MenuItem(true, 0,"Start", "assets/pixel font-7.ttf", 310, 240, 32*3, 20*3);
				MenuItem *exitButton = new MenuItem(true, 0,"Exit", "assets/pixel font-7.ttf", 310, 320, 32*3, 20*3);
				MenuItem *menuTitle = new MenuItem(false, 0,"Doors", "assets/pixel font-7.ttf", 304, 100, 32*4, 20*4);
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
					
					//if the time between each frame is less than the time between each frame in a 60 FPS setting, then we delay it by the difference between them to cap it at 60FPS.
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
					deltaTime = (float)(SDL_GetTicks() - frameStart)/1000;
					
				}
				currentScene = mainMenu->getSelectedScene();
				mainMenu->clean();
				delete(mainMenu);
				mainMenu = nullptr;
				}break;
			
			
			case LEVELMENU:{
					MenuScene* levelsMenu = new MenuScene();
					cout<<"Inside levelsMenu"<<endl;
					levelsMenu->init("assets/MenuImage.png", 2);
					MenuItem *menuTitle = new MenuItem(false, 0,"Levels", "assets/pixel font-7.ttf", 800/2 - (32*2), 100, 32*4, 20*4);
					
					MenuItem *firstLevelButton = new MenuItem(true, 0,"1", "assets/pixel font-7.ttf", 800/3 - (32*2) , 100 + 32*4, 32*4, 20*4);
					
					MenuItem *secondLevelButton = new MenuItem(true, 0,"2", "assets/pixel font-7.ttf",  800/2 - (32*2), 100 + 32*4, 32*4, 20*4);
					
					MenuItem *thirdLevelButton = new MenuItem(true, 0,"3", "assets/pixel font-7.ttf",  800/2 - (32*2) + 32*4+ 5, 100 + 32*4 , 32*4, 20*4);
					
					MenuItem *backButton = new MenuItem(true, 0,"Back", "assets/pixel font-7.ttf", 800/2 - (32*2), 100 + 32*4*2 + 20, 32*4, 20*4);
					
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
					
					deltaTime = (float)(SDL_GetTicks() - frameStart)/1000;
					
				}
				cout<<"leaving levelMenu"<<endl;
				currentScene = levelsMenu->getSelectedScene();
				levelsMenu->clean();
				delete(levelsMenu);
				levelsMenu = nullptr;
				}break;
				
			/*case FIRSTLEVEL:{
				//int levelnum = levelMenu->selectedLevel;
				//level[levelnum]->init();
				
				
				LevelScene* firstLevel = new LevelScene();
				firstLevel->init("assets/levelBackGround.png", 1);
				cout<<"inside first level."<<endl;
				
				GameObject* ground = new GameObject( 0, 600 - (12*4), 600, 12*4);
				ground->setSrcRect(0, 20, 64, 12);
				firstLevel->addPlatform(ground);
				
				Player* firstPlayer1 = new Player(float(380), float(300), 22*2, 28*2);
				firstPlayer1->setSrcRect(65, 0, 22, 28);	
				
				/*Player* secondPlayer1 = new Player(float(300), float(300), 22*2, 28*2);
				secondPlayer1->setSrcRect(65, 28, 22, 28);*/
				
				//firstLevel->addPlayer(firstPlayer1, true);
				//firstLevel->addPlayer(secondPlayer1, false);
				
				/*while(firstLevel->running()){
					frameStart = SDL_GetTicks();
					
					firstLevel->update(deltaTime);
					firstLevel->render();
					firstLevel->handleEvents(deltaTime);
					
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
					deltaTime = (float)(SDL_GetTicks() - frameStart)/1000;
					cout<<deltaTime<<endl;
					
				}
				currentScene = firstLevel->getSelectedScene();
				firstLevel->clean();
				delete(firstLevel);
				firstLevel = nullptr;
				cout<<"FIRSTLEVEL out"<<endl;
				}break;*/
				
			case FIRSTLEVEL:{
				LevelScene* firstLevel = new LevelScene();
				cout<<"inside first level."<<endl;
				firstLevel->init("assets/levelBackGround.png", 2);
				firstLevel->setLevel(FIRSTLEVEL);
				
				GameObject* ground11 = new GameObject( 0, 600 - (12*4), 600, 12*4);
				ground11->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground21 = new GameObject( 700, 400, 100, 12*4);
				ground21->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground31 = new GameObject( 300, 330, 280, 12*4);
				ground31->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground41 = new GameObject( 0, 280, 100, 12*4);
				ground41->setSrcRect(0, 20, 64, 12);
			
				
				GameObject* spike11 = new GameObject( 300 + 140, 330 - 24, 17*3, 8*3);
				spike11->setSrcRect(0, 32, 17, 8);
				GameObject* spike21 = new GameObject( 300, 600 - (12*4) - 24, 17*3, 8*3);
				spike21->setSrcRect(0, 32, 17, 8);
				/*GameObject* spike21 = new GameObject( 500 + 20, 400 - 24, 17*3, 8*3);
				spike21->setSrcRect(0, 32, 17, 8);
				GameObject* fireWall1 = new GameObject( 500 + 180, 400 - 28*4, 11*4, 28*4);
				fireWall1->setSrcRect(22, 32, 11, 28);*/
				GameObject* fireBall1 = new GameObject( 150, 290 , 10*3, 13*3);
				fireBall1->setSrcRect(0, 40, 10, 13);
				
				GameObject* fireBall21 = new GameObject( 220, 290 , 10*3, 13*3);
				fireBall21->setSrcRect(0, 40, 10, 13);
				
				
				GameObject* key1 = new GameObject( 35 , 280 - 30, 15*2, 10*2);
				key1->setSrcRect(33, 32, 15, 10);
				//GameObject* buttond1 = new GameObject( 100 + 150, 350 - 10, 11*2, 5*2);
				//button1->setSrcRect(33, 52, 11, 5);
				GameObject* door1 = new GameObject( 30, 600 - (12*4) - 37*4, 13*4, 37*4);
				door1->setSrcRect(48, 32, 13, 37);
				
				
				Player* firstPlayer1 = new Player(150, 600 - (12*4) - 28*2, 22*2, 28*2);
				firstPlayer1->setSrcRect(65, 0, 22, 28);	
				
				Player* secondPlayer1 = new Player(80, 600 - (12*4) - 28*2, 22*2, 28*2);
				secondPlayer1->setSrcRect(65, 28, 22, 28);	
				
				firstLevel->addPlatform(ground11);
				firstLevel->addPlatform(ground21);
				firstLevel->addPlatform(ground31);
				firstLevel->addPlatform(ground41);
				
				firstLevel->addSpike(spike11);
				firstLevel->addSpike(spike21);
				/*firstLevel->addfireWall(fireWall1);*/
				firstLevel->addfireBall(fireBall1);
				firstLevel->addfireBall(fireBall21);
				
				firstLevel->addKey(key1);
				firstLevel->addDoor(door1);
				//firstLevel->addButton(button1);
				
				firstLevel->addPlayer(firstPlayer1, true);
				firstLevel->addPlayer(secondPlayer1, false);
				
				/*I need to make a condition for if both are true, maybe if one true is found make all rest false and if no one is true, make the first true*/
				
				while(firstLevel->running()){
					frameStart = SDL_GetTicks();
					
					firstLevel->update(deltaTime);
					firstLevel->render();
					firstLevel->handleEvents(deltaTime);
					//cout<<"after handleEvents"<<endl;
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
					deltaTime = (float)(SDL_GetTicks() - frameStart)/1000;
					
				}
				currentScene = firstLevel->getSelectedScene();
				firstLevel->clean();
				delete(firstLevel);
				firstLevel = nullptr;
				cout<<"FIRSTLEVEL out"<<endl;
			}break;
				
			case SECONDLEVEL:{
				LevelScene* secondLevel = new LevelScene();
				cout<<"inside second level."<<endl;
				secondLevel->init("assets/levelBackGround.png", 2);
				secondLevel->setLevel(SECONDLEVEL);
				
				GameObject* ground1 = new GameObject( 250, 600 - (12*4), 350, 12*4);
				ground1->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground2 = new GameObject( 530, 200, 270, 12*4);
				ground2->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground3 = new GameObject( 0, 450, 200, 12*4);
				ground3->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground4 = new GameObject( 0, 200, 350, 12*4);
				ground4->setSrcRect(0, 20, 64, 12);
				
				
				GameObject* spike1 = new GameObject( 80 , 450 - 24, 17*3, 8*3);
				spike1->setSrcRect(0, 32, 17, 8);
				GameObject* spike2 = new GameObject( 100, 200 - 24, 17*3, 8*3);
				spike2->setSrcRect(0, 32, 17, 8);
				GameObject* fireWall = new GameObject( 500 + 180, 200 - 28*4, 11*4, 28*4);
				fireWall->setSrcRect(22, 32, 11, 28);
				GameObject* fireBall = new GameObject( 250, 200 - 13*3 - 5, 10*3, 13*3);
				fireBall->setSrcRect(0, 40, 10, 13);
				GameObject* fireBall2 = new GameObject( 400, 600 - (12*4) - 13*3 - 5, 10*3, 13*3);
				fireBall2->setSrcRect(0, 40, 10, 13);
				GameObject* fireBall3 = new GameObject( 450, 600 - (12*4) - 13*3 - 5, 10*3, 13*3);
				fireBall3->setSrcRect(0, 40, 10, 13);
				
				
				GameObject* key = new GameObject( 500 + 230, 200 - 30, 15*2, 10*2);
				key->setSrcRect(33, 32, 15, 10);
				GameObject* button = new GameObject( 20 , 450 - 10, 11*2, 5*2);
				button->setSrcRect(33, 52, 11, 5);
				GameObject* door = new GameObject( 700, 600 - (12*4) - 37*4, 13*4, 37*4);
				door->setSrcRect(48, 32, 13, 37);
				
				
				Player* firstPlayer = new Player(float(500), float(500), 22*2, 28*2);
				firstPlayer->setSrcRect(65, 0, 22, 28);	
				
				Player* secondPlayer = new Player(20, 200 - 28*2, 22*2, 28*2);
				secondPlayer->setSrcRect(65, 28, 22, 28);	
				
				secondLevel->addPlatform(ground1);
				secondLevel->addPlatform(ground2);
				secondLevel->addPlatform(ground3);
				secondLevel->addPlatform(ground4);
				
				secondLevel->addSpike(spike1);
				secondLevel->addSpike(spike2);
				secondLevel->addfireWall(fireWall);
				secondLevel->addfireBall(fireBall);
				secondLevel->addfireBall(fireBall2);
				secondLevel->addfireBall(fireBall3);
				
				secondLevel->addKey(key);
				secondLevel->addDoor(door);
				secondLevel->addButton(button);
				
				secondLevel->addPlayer(firstPlayer, true);
				secondLevel->addPlayer(secondPlayer, false);
				
				/*I need to make a condition for if both are true, maybe if one true is found make all rest false and if no one is true, make the first true*/
				
				while(secondLevel->running()){
					frameStart = SDL_GetTicks();
					
					secondLevel->update(deltaTime);
					secondLevel->render();
					secondLevel->handleEvents(deltaTime);
					//cout<<"after handleEvents"<<endl;
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
					deltaTime = (float)(SDL_GetTicks() - frameStart)/1000;
					
				}
				currentScene = secondLevel->getSelectedScene();
				secondLevel->clean();
				delete(secondLevel);
				secondLevel = nullptr;
				cout<<"SECONDLEVEL out"<<endl;
			}break;
			
			case THIRDLEVEL:{
				LevelScene* thirdLevel = new LevelScene();
				cout<<"inside third level."<<endl;
				thirdLevel->init("assets/levelBackGround.png", 3);
				thirdLevel->setLevel(THIRDLEVEL);
				
				GameObject* ground13 = new GameObject( 300, 600 - (12*4), 500, 12*4);
				ground13->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground23 = new GameObject( 400, 350, 450, 12*4);
				ground23->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground33 = new GameObject( 0, 450, 270, 12*4);
				ground33->setSrcRect(0, 20, 64, 12);
				
				GameObject* ground43 = new GameObject( 0, 200, 350, 12*4);
				ground43->setSrcRect(0, 20, 64, 12);
				
				
				GameObject* spike13 = new GameObject( 80 , 450 - 24, 17*3, 8*3);
				spike13->setSrcRect(0, 32, 17, 8);
				GameObject* spike23 = new GameObject( 100, 200 - 24, 17*3, 8*3);
				spike23->setSrcRect(0, 32, 17, 8);
				GameObject* spike33 = new GameObject( 500, 350 - 24, 17*3, 8*3);
				spike33->setSrcRect(0, 32, 17, 8);
				
				GameObject* fireBall3 = new GameObject( 250, 200 - 13*3 - 5, 10*3, 13*3);
				fireBall3->setSrcRect(0, 40, 10, 13);
				GameObject* fireBall23 = new GameObject( 450, 600 - (12*4) - 13*3 - 5, 10*3, 13*3);
				fireBall23->setSrcRect(0, 40, 10, 13);
				
				
				GameObject* fireWall3 = new GameObject( 700, 350 - 28*4, 11*4, 28*4);
				fireWall3->setSrcRect(22, 32, 11, 28);
				GameObject* fireWall23 = new GameObject( 45, 200 - 28*4, 11*4, 28*4);
				fireWall23->setSrcRect(22, 32, 11, 28);
				
				
				GameObject* key3 = new GameObject( 10, 200 - 30, 15*2, 10*2);
				key3->setSrcRect(33, 32, 15, 10);
				GameObject* button3 = new GameObject( 20 , 450 - 10, 11*2, 5*2);
				button3->setSrcRect(33, 52, 11, 5);
				GameObject* door3 = new GameObject( 700, 600 - (12*4) - 37*4, 13*4, 37*4);
				door3->setSrcRect(48, 32, 13, 37);
				
				
				Player* firstPlayer3 = new Player(600, 500, 22*2, 28*2);
				firstPlayer3->setSrcRect(65, 0, 22, 28);	
				
				Player* secondPlayer3 = new Player(800- 22*2 - 10, 350 - 28*2, 22*2, 28*2);
				secondPlayer3->setSrcRect(65, 28, 22, 28);	
				
				thirdLevel->addPlatform(ground13);
				thirdLevel->addPlatform(ground23);
				thirdLevel->addPlatform(ground33);
				thirdLevel->addPlatform(ground43);
				
				thirdLevel->addSpike(spike13);
				thirdLevel->addSpike(spike23);
				thirdLevel->addSpike(spike33);
				
				thirdLevel->addfireBall(fireBall3);
				thirdLevel->addfireBall(fireBall23);
				
				thirdLevel->addfireWall(fireWall3);
				thirdLevel->addfireWall(fireWall23);
				
				thirdLevel->addKey(key3);
				thirdLevel->addDoor(door3);
				thirdLevel->addButton(button3);
				
				thirdLevel->addPlayer(firstPlayer3, true);
				thirdLevel->addPlayer(secondPlayer3, false);
				
				
				while(thirdLevel->running()){
					frameStart = SDL_GetTicks();
					
					thirdLevel->update(deltaTime);
					thirdLevel->render();
					thirdLevel->handleEvents(deltaTime);
					
					frameTime = SDL_GetTicks() - frameStart;
					
					
					//we delay by frameDelay minus the frame time
					if(frameDelay>frameTime){
						SDL_Delay(frameDelay - frameTime);
					}
					
					deltaTime = (float)(SDL_GetTicks() - frameStart)/1000;
					if (deltaTime>0.15f)
						deltaTime=0.15f;
					
				}
				currentScene = thirdLevel->getSelectedScene();
				thirdLevel->clean();
				delete(thirdLevel);
				thirdLevel = nullptr;
				cout<<"thirdLevel out"<<endl;
				cout<<"THIRDLEVEL"<<endl;
			}break;
			
			
		}
		game->handleEvents();
		
	}
	SDL_DestroyTexture(Scene::textureSheet);
	Scene::textureSheet = nullptr;
	game->clean();
	cout<<"Game cleared"<<endl;
	
	return 0;
}
