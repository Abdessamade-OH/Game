#include "./header/menuScene.h"
#include "./header/TextureManager.h"
#include "./header/GameObject.h"
#include "iterator"

std::vector<MenuItem*>::iterator itr;
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

void MenuScene::addItem(MenuItem *item){
	this->items.push_back(item);
}

void MenuScene::handleEvents(){
	SDL_Event event;
	//int x,y;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				selected = QUIT;
				break;
			/*case SDL_MOUSEMOTION:{
				x=event.motion.x;
				y=event.motion.y;
				for(itr=items.begin(); itr!=items.end(); itr++){
					if(itr->)
				
			}break;}*/
			default:
				break;
		}
	}
} 
		
void MenuScene::clean(){
	backgroundImage = NULL;

	for(itr=items.begin(); itr!=items.end(); itr++){
		(*itr)->clean();
		delete(*itr);
	}
	
	items.clear();
	std::cout<<"Main menu cleared"<<std::endl;
}


