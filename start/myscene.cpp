/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <time.h>

#include "myscene.h"
#include "spaceship.h"
#include "spaceship.cpp"

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();
	Line* tmp = new Line();
	tmp->addPoint(-10.0f, -10.0f);
	tmp->addPoint(20.0f, 0.0f);
	tmp->addPoint(-10.0f, 10.0f);
	tmp->addPoint(-10.0f, -10.0f);

	//Create a BasicEntity as our spaceship.
	spaceship = new MyEntity();
	spaceship->addLine(tmp);
	spaceship->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	delete tmp; // delete when you're done with it.
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
	
}
