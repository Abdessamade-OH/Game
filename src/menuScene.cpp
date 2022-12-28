#include "./header/menuScene.h"

MenuScene(){}
~MenuScene(){}
		
void MenuScene::update(){}
void MenuScene::render(){
	SDL_RenderClear(Game::renderer);
	SDL_RenderCopy(Game::renderer, backgroundImage, NULL, NULL);
	SDL_RenderPresent(Game::renderer);
}

void MenuScene::init(){
	backgroundImage = TextureManager::LoadTexture("assets/MenuImage.png");
}
void MenuScene::handleEvents(){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				break;
			default:
				break;
		}
	}
} 
		
void MenuScene::clean(){
	backgroundImage = NULL;
}


		//bool running(){return isRunning;}
		//int selected(){return selected}//returns selected scene
