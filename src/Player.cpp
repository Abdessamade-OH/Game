#include "./header/player.h"

	
	
int Player::speed = 800;
float Player::gravity = -9.81;

Player::Player(int x, int y, int w, int h):GameObject::GameObject(x, y, w, h){}
Player::~Player(){}

void Player::fullCollision(SDL_Rect* rect){
	//SDL_Rect temp = {0,0,0,0};
	//std::cout<<temp.h<<std::endl;
	//if(temp.h!=0){
		if( (destRect.x + destRect.w >= rect->x) &&
			(destRect.x + destRect.w < rect->x + rect->w) &&
			(destRect.y + destRect.h > rect->y) &&
			(destRect.y < rect->y + rect->h) &&
			(dir==4) ){
				destRect.x = rect->x - destRect.w;
		}
		if( (destRect.x <= rect->x + rect->w) &&
			(destRect.x > rect->x) &&
			(destRect.y + destRect.h > rect->y) &&
			(destRect.y < rect->y + rect->h) &&
			(dir==3) ){
				destRect.x = rect->x + rect->w;
		}
			
		if( (destRect.y + destRect.h >= rect->y ) &&
			(destRect.y + destRect.h < rect->y + rect->h) &&
			(destRect.x + destRect.w > rect->x) &&
			(destRect.x < rect->x + rect->w) &&
			(dir==1) ){
				destRect.y = rect->y - destRect.h ;
		}
		if( (destRect.y <= rect->y + rect->h ) &&
			(destRect.y > rect->y) &&
			(destRect.x + destRect.w > rect->x) &&
			(destRect.x < rect->x + rect->w) &&
			(dir==0) ){
				destRect.y = rect->y + rect->h ;
		}
	//}
	//temp = destRect;
	//std::cout<<temp.h<<std::endl;
}

bool Player::jump(){}

bool Player::boundsCollision(){
	if(destRect.x + destRect.w >= 800-20)
		destRect.x=800-20 - destRect.w;
	else if(destRect.x<=20)
		destRect.x=20;
	if(destRect.y + destRect.h >600)
		return true;
	return false;
}

bool Player::collisionDetection(){}

void Player::update(){
	//GameObject::update();
	
}

/*void Player::move(int dir, float deltaTime){
	switch(dir){
		case 0://up
			this->destRect.y -= speed*deltaTime;
		break;
		case 1://down
			this->destRect.y += speed*deltaTime;
		break;
		case 3://left
			this->destRect.x -= speed*deltaTime;
		break;
		case 4://right
			this->destRect.x += speed*deltaTime;
		break;
	}
}*/
