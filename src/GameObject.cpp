#include "header/GameObject.h"
#include "header/TextureManager.h"
#include "header/scene.h"

GameObject::~GameObject(){}
GameObject::GameObject(/*const char* textureSheet,*/ int x, int y, int w, int h){

	//objectTexture = TextureManager::LoadTexture(textureSheet);
	//std::cout<<"object texture loaded"<<std::endl;
	//std::cout<<textureSheet<<std::endl;
	
	destRect.x = x;
	destRect.y = y;
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

	destRect.x = destRect.x ;
	destRect.y = destRect.y ;
	
	destRect.h = destRect.h;
	destRect.w = destRect.w;
}


void GameObject::render(){

	SDL_RenderCopy(Game::renderer, Scene::textureSheet, &srcRect, &destRect);
	//std::cout<<"object rendered"<<std::endl;
}

void GameObject::clean(){
	//SDL_DestroyTexture(objectTexture);
}

