#ifndef gameHeader.h
#define gameHeader.h
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef enum {MAINMENU, LEVELMENU, LEVELS} GameScene; 

class Game{

	public:
		Game();
		~Game();
		
		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		
		void handleEvents();
		void update();
		void render();
		void clean();
		bool running(){ return isRunning; }
		
		static SDL_Renderer* renderer;
		
	protected:
		bool isRunning = false;
		SDL_Window *window = NULL;

};

#endif

