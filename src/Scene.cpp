#include "./header/scene.h"
#include "./header/gameHeader.h"

Scene::Scene(){
	std::cout<<"menu created"<<std::endl;
}
Scene::~Scene(){}

/*void render(){
	backButton->render();
}
void update(){
	backButton->render();
}*/

SDL_Texture* Scene::textureSheet = nullptr;

void Scene::init(const char* filename, int which){
	/*switch(scene){
		case MAINMENU :
		case LEVELMENU :
			textureSheet = TextureManager::LoadTexture("assets/Button.png");
		break;
		case FIRSTLEVEL :
		case SECONDLEVEL :
		case THIRDLEVEL :
			textureSheet = TextureManager::LoadTexture("assets/ground.png");
		break;
		
	}*/
	this->which = which;
	backgroundImage = TextureManager::LoadTexture(filename);
	//textureSheet = TextureManager::LoadTexture(textureSheet);
	std::cout<<"background texture loaded"<<std::endl;
	std::cout<<filename<<std::endl;
	this->isRunning = true;
	
}
