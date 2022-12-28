#include "header/GameObject.h"
#include "header/TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y, int h, int w){

	objectTexture = TextureManager::LoadTexture(textureSheet);
	
	xpos = x;
	ypos = y;
	destRect.h = h;
	destRect.w = w;
}
void GameObject::setSrcRect(int x, int y, int h, int w){
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
	destRect.h = 28*2;
	destRect.w = 22*2;
}

void GameObject::render(){

	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}

