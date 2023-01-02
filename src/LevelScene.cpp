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
	bool isOver = false;
	std::vector<GameObject*>::iterator it;
	for(it=obstacles.begin(); it!=obstacles.end(); it++){
		(*it)->update();
	}
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->update(deltaTime);
		if( (*playerItr)->getSelected() ){
			isOver = (*playerItr)->boundsCollision();
			(*playerItr)->hitObstacle = false;
			for(it=obstacles.begin(); it!=obstacles.end(); it++){
				(*playerItr)->fullCollision((*it)->getDestRect());
				(*playerItr)->verticalCollision((*it)->getDestRect(), deltaTime);
			}
			if(key!=nullptr){
				if( (*playerItr)->collisionDetection( key->getDestRect() ) ){
					unlocked = true;
					std::cout<<"key touched"<<std::endl;
				}
			}
		}
	}
	
	if ( isOver==true ){
		selectedScene = LEVELMENU;
		isRunning=false;
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
	
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->render();
	}
	
	if(key!=nullptr){	
		//if(!unlocked)
			key->render();	
	}
	
	//std::cout<<"before render"<<std::endl;
	LevelbackButton->render();
	//std::cout<<"after render"<<std::endl;
	
	SDL_RenderPresent(Game::renderer);
}

void LevelScene::handleEvents(float deltaTime){
	SDL_Event event;
	int x,y;
	//std::cout<<deltaTime<<std::endl;
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
	
			case SDL_KEYDOWN:{
				//std::cout<<deltaTime<<std::endl;
				for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
					if( (*playerItr)->getSelected() ){
						//SDL_FRect* temp = (*playerItr)->getDestRect();
						switch( event.key.keysym.sym ){
							case SDLK_UP:
							case SDLK_w:
							case SDLK_z:
								if((*playerItr)->isAirborn() == false){
									//(*playerItr)->setVelocityY(-1);
									//(*playerItr)->hitObstacle = false;
									(*playerItr)->setVelocityY(-1);
									std::cout<<"up"<<(*playerItr)->hitObstacle<<std::endl;
									(*playerItr)->setAirborn(true);
									(*playerItr)->setJumpSpeed((*playerItr)->JUMPSPEED);
									std::cout<<(*playerItr)->getJumpSpeed()<<std::endl;
									
									(*playerItr)->jumped = true;
									
									(*playerItr)->beforeJumpVelocity=(*playerItr)->getVelocity();
								}
							break;

							/*case SDLK_DOWN:
							case SDLK_s:
								(*playerItr)->setVelocityY(1);
								(*playerItr)->setVelocityX(0);
								(*playerItr)->dir = 1;
								//destRect.y = ypos;
							break;*/

							case SDLK_LEFT:
							case SDLK_a:
							case SDLK_q:
								std::cout<<"left"<<(*playerItr)->hitObstacle<<std::endl;
								if(!(*playerItr)->isAirborn()){
									(*playerItr)->setVelocityX(-1);
									//(*playerItr)->setVelocityY(0);
									(*playerItr)->dir = 3;
									//destRect.x = xpos;
									std::cout<<"move left"<<std::endl;
									
									
								}
							break;

							case SDLK_RIGHT:
							case SDLK_d:
								if(!(*playerItr)->isAirborn()){
									(*playerItr)->setVelocityX(1);
									//(*playerItr)->setVelocityY(0);
									(*playerItr)->dir = 4;
									//destRect.x = xpos;
								}
							break;
							
							/*case SDLK_s:{
								(*playerItr)->setSelected(false);
								std::next((*playerItr))->setSelected(true);
							}break;*/
							
							case SDLK_1:{
								//if(players.size()>1){
									players[0]->setSelected(false);
									players[1]->setSelected(true);
								//}
							}break;
							
							case SDLK_2:{
								//if(players.size()>1){
									players[1]->setSelected(false);
									players[0]->setSelected(true);
								//}
							}break;

							default:
							break;
					}
				}
			}break;
			
			case SDL_KEYUP:{
				for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
					if( (*playerItr)->getSelected() ){
						switch( event.key.keysym.sym ){
			
							case SDLK_LEFT:
							case SDLK_a:
							case SDLK_q:
								//if( !(*playerItr)->isAirborn() ){
									(*playerItr)->setVelocityX(0);
									(*playerItr)->dir = 3;
								//}
							break;

							case SDLK_RIGHT:
							case SDLK_d:
								//if( !(*playerItr)->isAirborn() ){
									(*playerItr)->setVelocityX(0);
									(*playerItr)->dir = 4;
								//}
							break;
						}
					}
				}
			}break;
			
			default:
			break;
			
		}
	}
}
}

void LevelScene::addPlayer(Player* player, bool selected){
	player->setSelected(selected);
	players.push_back(player);
}
void LevelScene::clean(){
	std::vector<GameObject*>::iterator it;
	
	
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
	if(key!=nullptr){
		key->clean();
		delete(key);
	}
	std::cout<<"Level cleared"<<std::endl;
}

void LevelScene::addObstacle(GameObject *obstacle){
	obstacles.push_back(obstacle);
}

void LevelScene::addKey(GameObject* key){
	this->key = key;
}




