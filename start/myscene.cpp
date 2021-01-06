/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <time.h>

#include "myscene.h"
#include "bullet.h"

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	spaceship = new SpaceShip();
	bullet = new Bullet();
	ufo = new Ufo();

	this->addChild(spaceship);
	this->addChild(ufo);
	
	
	for (size_t i = 0; i < 15; i++)
	{
		this->addChild(bullet);
		std::cout << "added bullet";
	}

}


MyScene::~MyScene()
{
	
	
	this->removeChild(spaceship);
	this->removeChild(ufo);

	
	delete spaceship;
	delete ufo;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}




	this->updateSpaceShip(deltaTime);
}
void MyScene::updateSpaceShip(float deltaTime)
{

}

