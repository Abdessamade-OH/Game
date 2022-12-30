#include "./header/levelScene.h"

LevelScene::LevelScene(){
	/*backButton = new MenuItem(true, "Back", "assets/pixel font-7.ttf", "assets/Button.png", 20, 20, 32*4, 20*4);
	if(backButton==nullptr){
		
	}*/
}
LevelScene::~LevelScene(){}

void LevelScene::update(){
	std::vector<GameObject*>::iterator it;
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->update();
	}
	//backButton->update();
}

void LevelScene::render(){
	SDL_RenderClear(Game::renderer);

	SDL_RenderCopy(Game::renderer, this->backgroundImage, NULL, NULL);
	std::vector<GameObject*>::iterator it;
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->render();
	}
	//backButton->render();
	SDL_RenderPresent(Game::renderer);
}

void LevelScene::handleEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:{
				selectedScene = QUIT;
				isRunning=false;
				
			}break;
			
		}
	}
}

void LevelScene::clean(){
	std::vector<GameObject*>::iterator it;
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->clean();
		delete(*it);
	}
	SDL_DestroyTexture(backgroundImage);
	backgroundImage = NULL;
	obstacles.clear();
	//backButton->clean();
	std::cout<<"Level cleared"<<std::endl;
}

void LevelScene::addObstacle(GameObject *obstacle){
	obstacles.push_back(obstacle);
}
