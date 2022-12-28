#pragma once
#include "gameHeader.h"
#include "GameObject.h"

class MenuItem : public GameObject{
	private:
		bool buttonState;
		bool selected;
	public:
		void setButtonState(bool state);
		void setSelected(bool state);
		bool getButtonState(){return this->buttonState;}
		bool getSelected(){return this->selected;}
};
