#include "header/gameHeader.h"
#include "header/GameObject.h"

class MenuItem : public GameObject{
	private:
		bool button;
		bool selected;
	public:
		MenuItem(bool button, const char* textureSheet, int x, int y, int h, int w):GameObject(textureSheet, x, y, h, w){
			this->button = button;
		}
		~MenuItem(){}
};
