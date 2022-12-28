#ifndef scene.h
#define scene.h
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Scene{

	public:
		Scene();
		~Scene();
		
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

