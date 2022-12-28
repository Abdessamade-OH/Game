#pragma once
#include "gameHeader.h"
#include "GameObject.h"

class MenuItem : public GameObject{
	private:
		bool button;
		bool selected;
	public:
		MenuItem(bool button, const char* textureSheet, int x, int y, int h, int w);
		~MenuItem();
};
