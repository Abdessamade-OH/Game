#include "./header/gameHeader.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Scene *game = NULL;

int main(int argc, char* argv[]){
	GameScene currentScene = MAINMENU;
	const int FPS = 30;
	const int frameDelay = 1000/FPS; //we get the delta time for 60 FPS in ms (that's why we multiply by a 1000)
	
	Uint32 frameStart;
	int frameTime;

	game = new Scene();
	game->init("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, false);
	
	while(game->running()){
		
		//we get the time at when the frame starts
		frameStart = SDL_GetTicks();
	
		switch(currentScene){ //current scene will be an enum with three possibilites {mainMenu, levelMenu, levels} 
			case MAINMENU:
				break;
			
			case LEVELMENU:
				break;
				
			case LEVELS:
				//int levelnum = levelMenu->selectedLevel;
				//level[levelnum]->init();
				break;
		}
		game->handleEvents();
		game->update();
		game->render();
		
		//this allows us to know how much time all the treatments takes per frame.
		//we store the time a frame has taken in frameTime
		frameTime = SDL_GetTicks() - frameStart;
		
		//if the time between each frame is less than the time between each frame in a 60 FPS setting, then we delay it by the difference between them to cap it at 60FPS.
		if(frameDelay>frameTime){
			SDL_Delay(frameDelay - frameTime);
		}
		
		int deltaTime = SDL_GetTicks() - frameStart;
	}
	
	game->clean();
	
	
	
	return 0;
}
