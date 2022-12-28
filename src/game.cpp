#include "./header/gameHeader.h"
#include "./header/TextureManager.h"
#include "./header/GameObject.h"
using namespace std;

GameObject* player;

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
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				
			if(renderer == nullptr){
				cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<endl;
			}
			else{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				this->isRunning = true;
					
				player = new GameObject("assets/player.png", 0, 0, 28*2, 22*2);
				player->setSrcRect(0, 0, 28, 22);
			}
		}
	}
		
}
		
void Game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			this->isRunning = false;
			break;
		default:
			break;
	}
}
	
void Game::update(){
	counter++;
	player->update();
	cout<<counter<<endl;
}
	
void Game::render(){
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}
	
void Game::clean(){
	SDL_DestroyWindow(window);
	this->window = NULL;
	SDL_DestroyRenderer(renderer);
	this->renderer = NULL;
	SDL_Quit();
	
	

}


