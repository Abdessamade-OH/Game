#include "./header/menuScene.h"
//#include "./header/TextureManager.h"
//#include "./header/GameObject.h"
#include <iterator>


MenuScene::MenuScene(){
	std::cout<<"menu created"<<std::endl;	
}
MenuScene::~MenuScene(){}
		
void MenuScene::update(){
	for(int i = 0; i < items.size(); i++){
		items[i]->update();
	}
}

void MenuScene::render(){
	SDL_RenderClear(Game::renderer);

	SDL_RenderCopy(Game::renderer, this->backgroundImage, NULL, NULL);

	for(int i = 0; i < items.size(); i++){
		items[i]->render();
	}
	SDL_RenderPresent(Game::renderer);
}

/*void MenuScene::init(const char* filename, int which){
	this->which = which;
	backgroundImage = TextureManager::LoadTexture(filename);
	std::cout<<"background texture loaded"<<std::endl;
	this->isRunning = true;
}*/

void MenuScene::addItem(MenuItem *item){
	this->items.push_back(item);
}

void MenuScene::handleEvents(){
	SDL_Event event;
	int x,y;
	SDL_FRect* itemRect;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				this->isRunning = false;
				selectedScene = QUIT;
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
			if(this->which == 1){
						if(items[1]->getSelected()){
							std::cout<<"quit button clicked"<<std::endl;
							this->isRunning = false;
							selectedScene = QUIT;
							break;
						}
						if(items[0]->getSelected()){
							this->isRunning = false;
							selectedScene = LEVELMENU;
							break;
						}
			}
			else if(this->which == 2){
						if(items[1]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selectedScene = FIRSTLEVEL;
							break;
						}
						else if(items[2]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selectedScene = SECONDLEVEL;
							break;
						}
						else if(items[3]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selectedScene = THIRDLEVEL;
							break;
						}
						else if(items[4]->getSelected()){
							std::cout<<"firstLevel button clicked"<<std::endl;
							this->isRunning = false;
							selectedScene = MAINMENU;
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
	std::vector<MenuItem*>::iterator itr;
	SDL_DestroyTexture(backgroundImage);
	backgroundImage = NULL;

	for(itr=items.begin(); itr!=items.end(); itr++){
		(*itr)->clean();
		delete(*itr);
	}
	items.clear();
	std::cout<<"Main menu cleared"<<std::endl;
}


