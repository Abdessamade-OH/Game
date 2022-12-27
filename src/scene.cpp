#include "scene.h"
using namespace std;

Scene::Scene(){}
Scene::~Scene(){}
		
	void Scene::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	
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
				}
			}
		}
		
	}
		
	void Scene::handleEvents(){
		SDL_Event event;
		SDL_WaitEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				break;
			default:
				break;
		}
	}
	
	void Scene::update(){}
	
	void Scene::render(){
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	
	void Scene::clean(){
		SDL_DestroyWindow(window);
		this->window = NULL;
		SDL_DestroyRenderer(renderer);
		this->renderer = NULL;
		SDL_Quit();
	
	}


