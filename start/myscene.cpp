/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <time.h>

#include "myscene.h"

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	spaceship = new SpaceShip();
	
	this->addChild(spaceship);
}


MyScene::~MyScene()
{
	
	
	this->removeChild(spaceship);

	// delete myentity from the heap (there was a 'new' in the constructor)
	
	delete spaceship;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		spaceship->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		spaceship->scale = Point(1.0f, 1.0f);
	}


	this->updateSpaceShip(deltaTime);
}
void MyScene::updateSpaceShip(float deltaTime)
{

}