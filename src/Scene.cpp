#include "./header/scene.h"
#include "./header/gameHeader.h"

Scene::Scene(){
	std::cout<<"menu created"<<std::endl;
}
Scene::~Scene(){}


SDL_Texture* Scene::textureSheet = nullptr;

void Scene::init(const char* filename, int which){
	
	this->which = which;
	backgroundImage = TextureManager::LoadTexture(filename);
	//textureSheet = TextureManager::LoadTexture(textureSheet);
	std::cout<<"background texture loaded"<<std::endl;
	std::cout<<filename<<std::endl;
	this->isRunning = true;
	
	//clickEffect.load("assets/click.wav");
	
}
