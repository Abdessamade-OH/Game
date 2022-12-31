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
	int Player::speed = 100;
	float Player::gravity = -9.81;
	
	void Player::update(float deltaTime){
		GameObject::update();
		/*SDL_Event event;
	
		while(SDL_PollEvent(&event)!=0){
			if(event.type == SDL_KEYDOWN && selected){
				switch( event.key.keysym.sym ){
					case SDLK_UP:
						ypos -= speed*deltaTime;
						destRect.y = ypos;
					break;

					case SDLK_DOWN:
						ypos += speed*deltaTime;
						destRect.y = ypos;
					break;

					case SDLK_LEFT:
						xpos -= speed*deltaTime;
						destRect.x = xpos;
					break;

					case SDLK_RIGHT:
						xpos += speed*deltaTime;
						destRect.x = xpos;
					break;

					default:
					break;
				}
			}
		}*/
	}
