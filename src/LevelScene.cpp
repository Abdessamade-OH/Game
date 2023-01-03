#include "./header/levelScene.h"

LevelScene::LevelScene(){
	std::cout<<"test1"<<std::endl;
	MenuItem* tempBack = new MenuItem(true, 0,"Back", "assets/pixel font-7.ttf", 20, 20, 32*2, 20*2);
	MenuItem* successTemp = new MenuItem(false, 0,"Victory", "assets/pixel font-7.ttf", 800/2 - 32*3, 600/2 - 20*3, 32*6, 20*6);
	MenuItem* lossTemp = new MenuItem(false, 0,"Defeat", "assets/pixel font-7.ttf", 800/2 - 32*3, 600/2 - 20*3, 32*6, 20*6);
	MenuItem* player1Temp = new MenuItem(false, 3,"BLUE", "assets/pixel font-7.ttf", 800-32*2- 20, 20 , 32*2, 20*2);
	MenuItem* player2Temp = new MenuItem(false, 2,"RED", "assets/pixel font-7.ttf", 800-32*2- 20, 20 , 32*2, 20*2);

	tempBack->setSrcRect(32, 0, 32, 20);
	successTemp->setSrcRect(0, 0, 32, 20);
	lossTemp->setSrcRect(0, 0, 32, 20);
	
	player1Temp->setSrcRect(0, 0, 32, 20);
	player2Temp->setSrcRect(0, 0, 32, 20);

	this->LevelbackButton = tempBack;
	this->successButton = successTemp;
	this->lossButton = lossTemp;
	
	this->firstPlayerButton = player1Temp;
	this->secondPlayerButton = player2Temp;

	if(LevelbackButton == nullptr){
		std::cout<<"failed"<<std::endl;
	}
	tempBack = nullptr;
	successTemp = nullptr;
	lossTemp = nullptr;
	player1Temp = nullptr;
	player2Temp = nullptr;
}
LevelScene::~LevelScene(){}

void LevelScene::update(float deltaTime){
	//float x,y;
	
	
	for(it=platforms.begin(); it!=platforms.end(); it++){
		(*it)->update();
	}
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->update(deltaTime);
		if((*playerItr)->isAirborn())
			//std::cout<<"airborn"<<std::endl;
		for(it=spikes.begin(); it!=spikes.end(); it++){
			if( (*playerItr)->collisionDetection( (*it)->getDestRect()) ){
				std::cout<<"spike touch"<<std::endl;
				isOver=true;
				lossButton->render();
				//counter++;
				//if(counter>5000*deltaTime){
					this->isRunning = false;
					selectedScene = LEVELMENU;
				//}
			}
		}
		if( (*playerItr)->getSelected() ){
			isOver = (*playerItr)->boundsCollision();
			
			/*for(it=platforms.begin(); it!=platforms.end(); it++){
				(*playerItr)->fullCollision((*it)->getDestRect());
				(*playerItr)->verticalCollision((*it)->getDestRect(), deltaTime);
			}*/
			if(key!=nullptr && !unlocked){
				if( (*playerItr)->collisionDetection( key->getDestRect()) ){
					
					unlocked = true;
					std::cout<<"key touched"<<std::endl;
					key->setDestRect(20 + 32*2 + 20, 35, 15*1.5, 10*1.5);
				}
			}
			//(*playerItr)->fullCollision(key->getDestRect());
			if(door!=nullptr){
			
				if( (*playerItr)->collisionDetection( door->getDestRect()) )
					(*playerItr)->entered = true;
				else if(!(*playerItr)->collisionDetection( door->getDestRect())){
					(*playerItr)->entered = false;
					//(*playerItr)->counted = false;
				}
					
					
					//std::cout<<success<<std::endl;
					//std::cout<<players.size()<<std::endl;
					//std::cout<<(*playerItr)->entered<<std::endl;
			}
		}
		
	}
	
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->hitObstacle = false;
		for(it=platforms.begin(); it!=platforms.end(); it++){
			(*playerItr)->fullCollision((*it)->getDestRect());
			(*playerItr)->verticalCollision((*it)->getDestRect(), deltaTime);
		}
		
		if((*playerItr)->entered && !(*playerItr)->counted && unlocked){
			success++;
			(*playerItr)->counted = true;
		}
		
		
	}
		if(players.size()>1){
			
			if(!players[1]->counted){
				players[0]->fullCollision(players[1]->getDestRect());
				players[0]->verticalCollision(players[1]->getDestRect(), deltaTime);
			}
			
			if(!players[0]->counted){
				players[1]->fullCollision(players[0]->getDestRect());
				players[1]->verticalCollision(players[0]->getDestRect(), deltaTime);
			}
		}
		

		
	//std::cout<<counter<<std::endl;
	
	if(success == players.size()){
		std::cout<<"SUCCESS"<<std::endl;
		counter++;
		if(counter>5000*deltaTime){
			this->isRunning = false;
			selectedScene = LEVELMENU;
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
	
	for(it=platforms.begin(); it!=platforms.end(); it++){
		(*it)->render();
	}
	for(it=spikes.begin(); it!=spikes.end(); it++){
		(*it)->render();
	}
	
	if(door!=nullptr){
		door->render();
	}
	
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		if(!(*playerItr)->counted)
			(*playerItr)->render();
	}
	
	if(key!=nullptr){	
			key->render();	
	}
	
	
	if(success == players.size()){
		successButton->render();
		//SDL_Delay(2000);	
	}
	
	//std::cout<<"before render"<<std::endl;
	LevelbackButton->render();
	//std::cout<<"after render"<<std::endl;
	if(players.size()>=1){
		if(players[0]->getSelected())
			firstPlayerButton->render();
		else
			secondPlayerButton->render();
	}
	
	SDL_RenderPresent(Game::renderer);
}

void LevelScene::handleEvents(float deltaTime){
	SDL_Event event;
	int x,y;
	//std::cout<<deltaTime<<std::endl;
	if(success < players.size()){
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
								if(!(*playerItr)->isAirborn() && !(*playerItr)->counted){
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
								if(!(*playerItr)->isAirborn() && !(*playerItr)->counted){
									(*playerItr)->setVelocityX(-1);
									//(*playerItr)->setVelocityY(0);
									(*playerItr)->dir = 3;
									//destRect.x = xpos;
									std::cout<<"move left"<<std::endl;
								}
								
								if((*playerItr)->getJumpSpeed() >= -500  ){
									if((*playerItr)->getJumpSpeed() <= -480)
									(*playerItr)->beforeJumpVelocity.x=-1;
								}
								
							break;

							case SDLK_RIGHT:
							case SDLK_d:
								if(!(*playerItr)->isAirborn() && !(*playerItr)->counted){
									(*playerItr)->setVelocityX(1);
									//(*playerItr)->setVelocityY(0);
									(*playerItr)->dir = 4;
									//destRect.x = xpos;
								}
								
								if((*playerItr)->getJumpSpeed() >= -500 ){
									std::cout<<"airborn sss"<<std::endl;
									if((*playerItr)->getJumpSpeed() <= -480)
										(*playerItr)->beforeJumpVelocity.x=1;
								}
							break;
							
							/*case SDLK_s:{
								(*playerItr)->setSelected(false);
								std::next((*playerItr))->setSelected(true);
							}break;*/
							
							case SDLK_1:{
								if(players.size()>1){
									players[0]->setSelected(true);
									players[1]->setSelected(false);
								}
							}break;
							
							case SDLK_2:{
								if(players.size()>1){
									players[1]->setSelected(true);
									players[0]->setSelected(false);
								}
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
							
							case SDLK_UP:
							case SDLK_w:
							case SDLK_z:
								//if( !(*playerItr)->isAirborn() ){
									//(*playerItr)->setVelocityX(0);
									//(*playerItr)->dir = 4;
									(*playerItr)->setJumpSpeed(-(*playerItr)->JUMPSPEED/3);
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
}

void LevelScene::addPlayer(Player* player, bool selected){
	player->setSelected(selected);
	players.push_back(player);
}
void LevelScene::clean(){
	
	
	
	for(it=platforms.begin(); it!=platforms.end(); it++){
		(*it)->clean();
		delete(*it);
	}
	
	for(it=spikes.begin(); it!=spikes.end(); it++){
		(*it)->clean();
		delete(*it);
	}
	
	for(playerItr=players.begin(); playerItr!=players.end(); playerItr++){
		(*playerItr)->clean();
		delete(*playerItr);
	}
	
	SDL_DestroyTexture(backgroundImage);
	backgroundImage = NULL;
	
	platforms.clear();
	spikes.clear();
	players.clear();
	LevelbackButton->clean();
	successButton->clean();
	firstPlayerButton->clean();
	secondPlayerButton->clean();
	
	if(key!=nullptr){
		key->clean();
		delete(key);
	}
	if(door!=nullptr){
		door->clean();
		delete(door);
	}
	std::cout<<"Level cleared"<<std::endl;
}

void LevelScene::addPlatform(GameObject *platform){
	platforms.push_back(platform);
}

void LevelScene::addSpike(GameObject *spike){
	spikes.push_back(spike);
}

void LevelScene::addKey(GameObject* key){
	this->key = key;
}

void LevelScene::addDoor(GameObject* door){
	this->door = door;
}




