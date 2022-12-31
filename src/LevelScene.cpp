#include "./header/levelScene.h"

LevelScene::LevelScene(){
	std::cout<<"test1"<<std::endl;
	MenuItem* tempButton = new MenuItem(true, "Back", "assets/pixel font-7.ttf", 20, 20, 32*2, 20*2);
	std::cout<<"test2"<<std::endl;
	tempButton->setSrcRect(32, 0, 32, 20);
	std::cout<<"test3"<<std::endl;
	
	this->LevelbackButton = tempButton;
	
	std::cout<<"test4"<<std::endl;
	//tempButton->clean();
	std::cout<<"test5"<<std::endl;
	//delete(tempButton);
	std::cout<<"test6"<<std::endl;
	//tempButton =nullptr;
	std::cout<<"test7"<<std::endl;
	if(LevelbackButton == nullptr){
		std::cout<<"failed"<<std::endl;
	}
	tempButton = nullptr;
}
LevelScene::~LevelScene(){}

void LevelScene::update(float deltaTime){
	std::vector<GameObject*>::iterator it;
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->update();
	}
	std::vector<Player*>::iterator playerItr;
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->update(deltaTime);
	}
	
	//std::cout<<"before update"<<std::endl;
	LevelbackButton->update();
	//std::cout<<"after update"<<std::endl;
}

void LevelScene::render(){
	SDL_RenderClear(Game::renderer);

	SDL_RenderCopy(Game::renderer, this->backgroundImage, NULL, NULL);
	std::vector<GameObject*>::iterator it;
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->render();
	}
	
	std::vector<Player*>::iterator playerItr;
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->render();
	}
	
	//std::cout<<"before render"<<std::endl;
	LevelbackButton->render();
	//std::cout<<"after render"<<std::endl;
	
	
	SDL_RenderPresent(Game::renderer);
}

void LevelScene::handleEvents(){
	SDL_Event event;
	int x,y;
	
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:{
				selectedScene = QUIT;
				isRunning=false;
				
			}break;
			
			case SDL_MOUSEMOTION:{
				x=event.motion.x;
				y=event.motion.y;
				
				//itemRect = (LevelbackButton->getDestRect());
				
				if(	x>=LevelbackButton->getDestRect()->x &&
					(x<= (LevelbackButton->getDestRect()->x + LevelbackButton->getDestRect()->w)) &&
					y>=LevelbackButton->getDestRect()->y &&
					(y<= (LevelbackButton->getDestRect()->y + LevelbackButton->getDestRect()->h))	&&
					LevelbackButton->getButtonState()
					){
						if(!LevelbackButton->getSelected()){
							
							std::cout<<"Inside level Button"<<std::endl;
							LevelbackButton->setSelected(true);
							
						}
				}
				else{
					if(LevelbackButton->getSelected())
						LevelbackButton->setSelected(false);
				}
				
			}break;
			
			case SDL_MOUSEBUTTONDOWN:{
				//if(this->which == 1){
			
				if(LevelbackButton->getSelected()){
					this->isRunning = false;
					selectedScene = LEVELMENU;
					break;
				}
				
			}break;
			
		}
	}
}

void LevelScene::clean(){
	std::vector<GameObject*>::iterator it;
	std::vector<Player*>::iterator playerItr;
	
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->clean();
		delete(*it);
	}
	
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->clean();
		delete(*playerItr);
	}
	
	SDL_DestroyTexture(backgroundImage);
	backgroundImage = NULL;
	
	obstacles.clear();
	players.clear();
	LevelbackButton->clean();
	std::cout<<"Level cleared"<<std::endl;
}

void LevelScene::addObstacle(GameObject *obstacle){
	obstacles.push_back(obstacle);
}
