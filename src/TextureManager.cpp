#include "./header/TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren){
	
	SDL_Texture* texture = NULL;
	SDL_Surface* tmpSurface = IMG_Load(fileName);
	if( tmpSurface==nullptr )
		std::cout<<"IMG_Load Error: "<<SDL_GetError()<<std::endl;
	else{
		texture = SDL_CreateTextureFromSurface(ren, tmpSurface);
		if( texture==nullptr )
			std::cout<<"SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<std::endl;
		SDL_FreeSurface(tmpSurface);
		tmpSurface = NULL;
	}
	return texture;
}
