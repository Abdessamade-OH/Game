#pragma once
#include "gameHeader.h"
#include "GameObject.h"

class Player : public GameObject {

	
	public:
	Player(int x, int y, int w, int h);
	~Player();
	
	void fullCollision(SDL_Rect* rect);
	bool jump();
	bool boundsCollision();
	bool collisionDetection();
	static int speed;
	static float gravity;
	void update();
	bool getSelected(){return selected;}
	void setSelected(bool selected){this->selected = selected;}
	//void move(int dir, float deltaTime);
	bool getCanJump(){return this->canJump;}	
	int dir = 0;
	private:
		
		float velocity;
		bool canJump = true;
		bool selected;
		
};
