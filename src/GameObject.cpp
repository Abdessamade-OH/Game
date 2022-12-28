#include "header/GameObject.h"
#include "header/TextureManager.h"
GameObject::~GameObject(){}
GameObject::GameObject(const char* textureSheet, int x, int y, int w, int h){

	objectTexture = TextureManager::LoadTexture(textureSheet);
	std::cout<<"object texture loaded"<<std::endl;
	std::cout<<textureSheet<<std::endl;
	xpos = x;
	ypos = y;
	destRect.h = h;
	destRect.w = w;
	
	/*srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 0;
	srcRect.w = 0;*/
}
void GameObject::setSrcRect(int x, int y, int w, int h){
	srcRect.x = x;
	srcRect.y = y;
	srcRect.h = h;
	srcRect.w = w;
}
SDL_Rect* GameObject::getDestRect(){
	return &destRect;
}
void GameObject::update(){

	destRect.x = xpos;
	destRect.y = ypos;
	
	/*destRect.h = h;
	destRect.w = w;*/
	
}

void GameObject::render(){

	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
	//std::cout<<"object rendered"<<std::endl;
}

