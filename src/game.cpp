#include "./header/gameHeader.h"
#include "./header/TextureManager.h"
#include "./header/GameObject.h"
using namespace std;


float counter = 0;

SDL_Renderer* Game::renderer = nullptr;

Game::Game(){}
Game::~Game(){}
		
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	int flags = 0;
	if(fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
		
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
	}
	else{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
			if(window == nullptr){
			cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
		}
		else{
			cout<<"Window created."<<endl;
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				
			if(renderer == nullptr){
				cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<endl;
			}
			else{
				cout<<"renderer created."<<endl;
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				this->isRunning = true;
				
			}
		}
	}
		
}
		
void Game::handleEvents(){
	SDL_Event event;
	if( SDL_PollEvent(&event) ){
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				break;
			default:
				break;
		}
	}
}
	
	
void Game::clean(){
	SDL_DestroyWindow(window);
	this->window = NULL;
	SDL_DestroyRenderer(renderer);
	this->renderer = NULL;
	SDL_Quit();
}


