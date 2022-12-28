#include "./header/menuScene.h"
#include "./header/TextureManager.h"

MenuScene::MenuScene(){}
MenuScene::~MenuScene(){}
		
void MenuScene::update(){}
void MenuScene::render(){
	SDL_RenderClear(Game::renderer);
	SDL_RenderCopy(Game::renderer, backgroundImage, NULL, NULL);
	SDL_RenderPresent(Game::renderer);
}

void MenuScene::init(const char* filename){
	backgroundImage = TextureManager::LoadTexture(filename);
	std::cout<<"texture loaded"<<std::endl;
	this->isRunning = true;
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
}


	//bool running(){return isRunning;}
	//int selected(){return selected}//returns selected scene
