#pragma once
#include "gameHeader.h"
#include "GameObject.h"

typedef struct {
	int x;
	int y;
}Velocity;

class Player : public GameObject {

	
	public:
	Player(int x, int y, int w, int h);
	~Player();
	
	void fullCollision(SDL_FRect* rect);
	void jump();
	bool boundsCollision();
	bool collisionDetection();
	static int speed;
	static float gravity;
	void update(double deltaTime);
	bool getSelected(){return selected;}
	void setSelected(bool selected){this->selected = selected;}
	//void move(int dir, float deltaTime);
	bool getCanJump(){return this->canJump;}	
	int dir = 0;
	Velocity setVelocityX(int veloX){ velocity.x = veloX;}
	Velocity setVelocityY(int veloY){ velocity.y = veloY;}
	private:
		
		Velocity velocity = {0, 0};
		bool canJump = true;
		bool selected;
		
};
