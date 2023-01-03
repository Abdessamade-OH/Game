#include "./header/player.h"

	
	
int Player::speed = 350;
float Player::gravity = 1200;

Player::Player(float x, float y, int w, int h):GameObject::GameObject(x, y, w, h){}
Player::~Player(){}

void Player::fullCollision(SDL_FRect* rect){
	//SDL_Rect temp = {0,0,0,0};
	//std::cout<<temp.h<<std::endl;
	//if(temp.h!=0){
		if( (destRect.x + destRect.w >= rect->x - 5) &&
			(destRect.x + destRect.w < rect->x + rect->w) &&
			(destRect.y + destRect.h > rect->y +5) &&
			(destRect.y < rect->y + rect->h -5) &&
			(velocity.x==1) ){
				destRect.x = rect->x - destRect.w;
				//jumpSpeed = 0;
				//beforeJumpVelocity.x = 0;
				//ju
		}
		if( (destRect.x <= rect->x + rect->w + 5) &&
			(destRect.x > rect->x) &&
			(destRect.y + destRect.h > rect->y +5) &&
			(destRect.y < rect->y + rect->h -5) &&
			(velocity.x==-1) ){
				destRect.x = rect->x + rect->w;
				//jumpSpeed = 0;
		}
		
		
		if( (destRect.y + destRect.h >= rect->y ) &&
			(destRect.y + destRect.h < rect->y + rect->h) &&
			(destRect.x + destRect.w > rect->x) &&
			(destRect.x < rect->x + rect->w) &&
			(velocity.y==1) ){
				destRect.y = rect->y - destRect.h ;
				
		}
		if( (destRect.y <= rect->y + rect->h +5) &&
			(destRect.y > rect->y) &&
			(destRect.x + destRect.w > rect->x + 7) &&
			(destRect.x < rect->x + rect->w - 7) &&
			(velocity.y==-1) &&
			(airborn)){
				destRect.y = rect->y + rect->h ;
				jumpSpeed=100;
				
		}
	//}
	//temp = destRect;
	//std::cout<<temp.h<<std::endl;
}

void Player::verticalCollision(SDL_FRect* rect, float deltaTime){
	
	if( (destRect.x + destRect.w > rect->x ) &&
		(destRect.x < rect->x + rect->w ) &&
		(rect->y >= destRect.y + destRect.h) &&
		(rect->y <= destRect.y + destRect.h + (jumpSpeed*deltaTime)) 
		//(jumpSpeed>=0) 
			)
		{
			//velocity.y = 1;
			//airborn = false;
			hitObstacle = true;
			jumpSpeed = 0.0f;
			destRect.y = rect->y - destRect.h;
			jumped = false;
			
			//the solution to the key being released but in case player was comming of air, then make vel.x=0
			if(airborn)
				beforeJumpVelocity.x = 0;
			//std::cout<<"hit obstacle"<<hitObstacle<<std::endl;
		}	
}



void Player::jump(){

}

bool Player::boundsCollision(){
	if(destRect.x + destRect.w >= 800-20)
		destRect.x=800-20 - destRect.w;
	else if(destRect.x<=20)
		destRect.x=20;
	if(destRect.y + destRect.h >600)
		return true;
	return false;
}


bool Player::collisionDetection(SDL_FRect* rect){
	
	
	if( /*(rect->x + rect->w>= destRect.x) &&
		(rect->x <= destRect.x + destRect.w) &&
		(rect->y + rect->h >= destRect.y)&&
		(rect->y <= destRect.y + destRect.h)*/
		
		(destRect.x + destRect.w >= rect->x) &&
		(rect->x + rect->w >= destRect.x)&&
		(destRect.y + destRect.h >= rect->y) &&
		(rect->y + rect->h >= destRect.y)
		 )
		{
			return true;
		}
	return false;
}


void Player::update(float deltaTime){
	//GameObject::update();
	if(!airborn)
		destRect.x += velocity.x*speed*deltaTime;
	else{
		if(jumped)
			destRect.x += beforeJumpVelocity.x*speed*deltaTime*0.7;
		else
			destRect.x += velocity.x*speed*deltaTime*0.1;
	}
	//destRect.y += velocity.y*speed*deltaTime;
	
	//destRect.x += 100 * 0.01666;
	
	/*destRect.y += jumpSpeed*deltaTime*velocity.y;
	if(velocity.y == -1)
		jumpSpeed += gravity;*/
	//std::cout<<"function update. hit obstacle"<<hitObstacle<<std::endl;
	if(!hitObstacle){
		std::cout<<jumpSpeed<<std::endl;
		destRect.y += jumpSpeed*deltaTime;
		jumpSpeed += gravity*deltaTime;
		if(jumpSpeed>50)
			velocity.y = 1;
		if (jumpSpeed>600)
			jumpSpeed = 600;
			
		airborn = true;
		
	}
	else
		airborn = false;
	
	//std::cout<<"airborn"<<airborn<<std::endl;
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
