#include "./header/fireBall.h"

FireBall::FireBall(float x, float y, int w, int h):GameObject::GameObject(x, y, w, h){};
FireBall::~FireBall(){}

void FireBall::update(float deltaTime){
	
	std::cout<<"inside"<<std::endl;
	if(type == 1){
		if(originalPos.x == destRect.x)
			destRect.x += horizontalSpeed*deltaTime;
		else if(destRect.x >= originalPos.x + distance)
			destRect.x -= horizontalSpeed*deltaTime;
		else if(destRect.x <= originalPos.x - distance)
			destRect.x += horizontalSpeed*deltaTime;
	}
}

void FireBall::render(){}


