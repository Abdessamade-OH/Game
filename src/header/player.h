#pragma once
#include "gameHeader.h"
#include "GameObject.h"

typedef struct {
	int x;
	int y;
}Velocity;

class Player : public GameObject {

	
	public:
	Player(float x, float y, int w, int h);
	~Player();
	
	void fullCollision(SDL_FRect* rect);
	void verticalCollision(SDL_FRect* rect, float deltaTime);
	void jump();
	bool boundsCollision();
	bool collisionDetection(SDL_FRect* rect);
	static int speed;
	static float gravity;
	void update(float deltaTime);
	bool getSelected(){return selected;}
	void setSelected(bool selected){this->selected = selected;}
	//void move(int dir, float deltaTime);
	//bool getCanJump(){return this->canJump;}	
	int dir = 0;
	Velocity setVelocityX(int veloX){ velocity.x = veloX;}
	Velocity setVelocityY(int veloY){ velocity.y = veloY;}
	bool isAirborn(){return airborn;}
	void setAirborn(bool air){this->airborn = air;}
	void setJumpSpeed(float num){jumpSpeed = num;}
	float getJumpSpeed(){return jumpSpeed;}
	bool hitObstacle = false;
	float JUMPSPEED = -500;
	
	bool jumped = false;
	
	Velocity beforeJumpVelocity = {0,0};
	Velocity getVelocity(){return velocity;}
	bool entered = false;
	bool counted = false;
	private:
		
		Velocity velocity = {0, 0};
		
		bool selected;
		bool airborn = true;
		float jumpSpeed = 0.0f;
		
		
};
