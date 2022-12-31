#include "./header/menuItem.h"
#include "./header/GameObject.h"
#include "./header/TextureManager.h"

MenuItem::~MenuItem(){}

MenuItem::MenuItem(bool buttonState, const char* text, const char* fontFile, /*const char* textureSheet,*/ int x, int y, int w, int h):GameObject(/*textureSheet,*/ x, y, w, h){
	this->text = text;
	TTF_Init();
	this->button = buttonState;
	font = TTF_OpenFont(fontFile, 32);
	if( font==nullptr )
		std::cout<<"TTF_OpenFont Error: "<<SDL_GetError()<<std::endl;
	else{
		textSurface = TTF_RenderText_Solid(font, text, textColor[0]);
		if(textSurface==nullptr)
			std::cout<<"TTF_RenderText_Solid Error: "<<SDL_GetError()<<std::endl;
		else{
			textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
			SDL_FreeSurface(textSurface);
			if(textTexture==nullptr)
				std::cout<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
		}
	}
}


void MenuItem::setSelected(bool state){
	this->selected = state;
	if(state == true){
		std::cout<<text<<std::endl;
		textSurface = TTF_RenderText_Solid(font, text, textColor[1]);
		if(textSurface==nullptr)
			std::cout<<"TTF_RenderText_Solid Error: "<<SDL_GetError()<<std::endl;
		else{
			textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
			SDL_FreeSurface(textSurface);
			if(textTexture==nullptr)
				std::cout<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
		}
	}
	else{
		textSurface = TTF_RenderText_Solid(font, text, textColor[0]);
		if(textSurface==nullptr)
			std::cout<<"TTF_RenderText_Solid Error: "<<SDL_GetError()<<std::endl;
		else{
			textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
			SDL_FreeSurface(textSurface);
			if(textTexture==nullptr)
				std::cout<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
		}
	}
}

void MenuItem::render(){
	
	//std::
	GameObject::render();
	//SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
	SDL_RenderCopy(Game::renderer, textTexture, NULL, &textRect);
	//SDL_BlitSurface(text, NULL, destRect, )
}

void MenuItem::clean(){
	std::cout<<"cleaning object, menuItem"<<std::endl;
	GameObject::clean();
	//SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
	TTF_CloseFont(font);
	TTF_Quit();
}

void MenuItem::update(){
	//std::cout<<"before update inside"<<std::endl;
	GameObject::update();
	//std::cout<<"after update, and before text inside"<<std::endl;
	textRect = (SDL_Rect){destRect.x + 5, destRect.y + 5, destRect.w - 10, destRect.h - 10};
	//std::cout<<"after text inside"<<std::endl;
}
