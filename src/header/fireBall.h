#pragma once
#include "GameObject.h"

class FireBall : public GameObject{
	
	private:
		
		SDL_FRect originalPos = destRect;
		int type = 1;	
		float horizontalSpeed = 200;
		float distance = 75;
	public:
		
		FireBall(float x, float y, int w, int h);
		~FireBall();
		void update(float deltaTime);
		void render();
};
