#include "./header/menuScene.h"
#include "./header/TextureManager.h"
#include "./header/GameObject.h"
#include <iterator>

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

void MenuScene::init(const char* filename, int whichMenu){
	this->whichMenu = whichMenu;
	backgroundImage = TextureManager::LoadTexture(filename);
	std::cout<<"background texture loaded"<<std::endl;
	this->isRunning = true;
}

void MenuScene::addItem(MenuItem *item){
	this->items.push_back(item);
}

void MenuScene::handleEvents(){
	SDL_Event event;
	int x,y;
	SDL_Rect* itemRect;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				selected = QUIT;
				break;
			case SDL_MOUSEMOTION:{
				x=event.motion.x;
				y=event.motion.y;
				for(int i=0; i<items.size(); i++){
					itemRect = (items[i]->getDestRect());
					if(	x>=itemRect->x &&
						(x<= (itemRect->x + itemRect->w)) &&
						y>=itemRect->y &&
						(y<= (itemRect->y + itemRect->h))	&&
						items[i]->getButtonState()
						){
							if(!items[i]->getSelected()){
								
								std::cout<<"Inside menu item"<<std::endl;
								items[i]->setSelected(true);
								
							}
						}
						else{
							if(items[i]->getSelected()){
								items[i]->setSelected(false);
							}
						}
				}
			}break;
			
			/*case SDL_KEYDOWN:{
				for(int i=0; i<items.size(); i++){
					items[i]->setSelected(true);
				}
			}break;
			case SDL_KEYUP:{
				for(int i=0; i<items.size(); i++){
					items[i]->setSelected(false);
				}
			}break;
			*/
		case SDL_MOUSEBUTTONDOWN:{
			if(this->whichMenu == 1){
						if(items[1]->getSelected()){
							std::cout<<"quit button clicked"<<std::endl;
							this->isRunning = false;
							selected = QUIT;
							break;
						}
						if(items[0]->getSelected()){
							this->isRunning = false;
							selected = LEVELMENU;
							break;
						}
			}
			else if(this->whichMenu == 2){
						if(items[1]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selected = FIRSTLEVEL;
							break;
						}
						else if(items[1]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selected = SECONDLEVEL;
							break;
						}
						else if(items[1]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selected = THIRDLEVEL;
							break;
						}
						else if(items[4]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selected = MAINMENU;
							break;
						}
			}
		}break;
		default:
				break;
		}
	}
} 
		
void MenuScene::clean(){
	SDL_DestroyTexture(backgroundImage);
	backgroundImage = NULL;

	for(itr=items.begin(); itr!=items.end(); itr++){
		(*itr)->clean();
		delete(*itr);
	}
	
	items.clear();
	std::cout<<"Main menu cleared"<<std::endl;
}


