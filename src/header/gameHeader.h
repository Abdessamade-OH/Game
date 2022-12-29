#ifndef gameHeader.h
#define gameHeader.h
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef enum {QUIT, MAINMENU, LEVELMENU, FIRSTLEVEL, SECONDLEVEL, THIRDLEVEL} GameScene; //was gonna make levelmenu return the selected level and add it to the levels Vector, but this is just easier

class Game{

	public:
		Game();
		~Game();
		
		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		
		void handleEvents();
		//void update();
		//void render();
		void clean();
		bool running(){ return isRunning; }
		void setRunning(bool state){this->isRunning = state;};
		static SDL_Renderer* renderer;
		
	protected:
		bool isRunning = false;
		SDL_Window *window = NULL;

};

#endif

