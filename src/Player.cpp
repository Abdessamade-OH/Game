#include "./header/player.h"

	Player::Player(int x, int y, int w, int h):GameObject::GameObject(x, y, w, h){}
	Player::~Player(){}
	
	void Player::fullCollision(){}
	bool Player::jump(){}
	bool Player::boundsCollision(){
		if(destRect.x + destRect.w >= 800-20)
			destRect.x=800-20 - destRect.w;
		else if(destRect.x<=20)
			destRect.x=20;
		if(destRect.y + destRect.h >600-12*3)
			return true;
		return false;
	}
	bool Player::collisionDetection(){}
	int Player::speed = 500;
	float Player::gravity = -9.81;
	
	void Player::update(){
		GameObject::update();
		
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
