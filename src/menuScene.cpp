#include "./header/menuScene.h"
#include "./header/TextureManager.h"
#include "./header/GameObject.h"
#include "iterator"


MenuScene::MenuScene(){}
MenuScene::~MenuScene(){}
		
void MenuScene::update(){
	for(int i = 0; i < items.size(); i++){
		items[i]->update();
	}
}

void MenuScene::render(){
	SDL_RenderClear(Game::renderer);
	
	SDL_RenderCopy(Game::renderer, backgroundImage, NULL, NULL);
	
	for(int i = 0; i < items.size(); i++){
		items[i]->render();
	}
	SDL_RenderPresent(Game::renderer);
	//std::cout<<"rendering"<<std::endl;
}

void MenuScene::init(const char* filename){
	backgroundImage = TextureManager::LoadTexture(filename);
	std::cout<<"background texture loaded"<<std::endl;
	this->isRunning = true;
}

void MenuScene::addItem(GameObject *item){
	this->items.push_back(item);
}

void MenuScene::handleEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				selected = QUIT;
				break;
			default:
				break;
		}
	}
} 
		
void MenuScene::clean(){
	backgroundImage = NULL;
	std::vector<GameObject*>::iterator itr;
	for(itr=items.begin(); itr!=items.end(); itr++){
		delete(*itr);
	}
	
	items.clear();
	std::cout<<"Main menu cleared"<<std::endl;
}


