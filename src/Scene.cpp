#include "./header/scene.h"

Scene::Scene(){
	std::cout<<"menu created"<<std::endl;
}
Scene::~Scene(){}


void Scene::init(const char* filename, int which){
	this->which = which;
	backgroundImage = TextureManager::LoadTexture(filename);
	std::cout<<"background texture loaded"<<std::endl;
	std::cout<<filename<<std::endl;
	this->isRunning = true;
	
}
