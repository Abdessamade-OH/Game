#include "./header/menuItem.h"
#include "./header/GameObject.h"
#include "./header/TextureManager.h"

MenuItem::~MenuItem(){}

MenuItem::MenuItem(bool buttonState, const char* text, const char* fontFile, const char* textureSheet, int x, int y, int w, int h):GameObject(textureSheet, x, y, w, h){
	TTF_Init();
	this->button = buttonState;
	font = TTF_OpenFont(fontFile, 32);
	if( font==nullptr )
		std::cout<<"TTF_OpenFont Error: "<<SDL_GetError()<<std::endl;
	else{
		textSurface = TTF_RenderText_Solid(font, text, textColor);
		if(textSurface==nullptr)
			std::cout<<"TTF_RenderText_Solid Error: "<<SDL_GetError()<<std::endl;
		else{
			textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
			if(textTexture==nullptr)
				std::cout<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
		}
	}
}

void MenuItem::setSelected(bool state){
	this->selected = state;
}

void MenuItem::render(){
	
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
	SDL_RenderCopy(Game::renderer, textTexture, NULL, &textRect);
	//SDL_BlitSurface(text, NULL, destRect, )
}

void MenuItem::clean(){
	std::cout<<"cleaning object, menuItem"<<std::endl;
	GameObject::clean();
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
	TTF_CloseFont(font);
	TTF_Quit();
}

void MenuItem::update(){
	GameObject::update();
	textRect = (SDL_Rect){destRect.x + 5, destRect.y + 5, destRect.w - 10, destRect.h - 10};
}
