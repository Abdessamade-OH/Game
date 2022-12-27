#include "scene.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "scene.h"

using namespace std;

Scene *game = NULL;

int main(int argc, char* argv[]){

	game = new Scene();
	game->init("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, false);
	
	while(game->running()){
		game->handleEvents();
		game->update();
		game->render();
	}
	
	game->clean();
	
	return 0;
}
