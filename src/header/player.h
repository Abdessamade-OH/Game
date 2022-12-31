#pragma once
#include "gameHeader.h"
#include "GameObject.h"

class Player : public GameObject {

	
	public:
	Player(int x, int y, int w, int h);
	~Player();
	
	void fullCollision();
	bool jump();
	bool boundsCollision();
	bool collisionDetection();
	static int speed;
	static float gravity;
	void update();
	bool getSelected(){return selected;}
	
	bool getCanJump(){return this->canJump;}	

	private:
		float velocity;
		bool canJump = true;
		bool selected = true;
		
};
