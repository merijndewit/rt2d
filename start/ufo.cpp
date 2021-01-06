/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "ufo.h"
#include "myscene.h"






Ufo::Ufo() : Entity()
{
	//movement ship
	this->position = Point2(SWIDTH / 8, SHEIGHT / 8);

	Line* tmp = new Line();
	tmp->addPoint(-35, 10);
	tmp->addPoint(-15, 10);
	tmp->addPoint(-10, 12);
	tmp->addPoint(10, 12);
	tmp->addPoint(15, 10);
	tmp->addPoint(35 ,10);
	tmp->addPoint(40, 5);
	tmp->addPoint(40, -5);
	tmp->addPoint(35, -10);
	tmp->addPoint(25, -10);
	tmp->addPoint(20, -13);
	tmp->addPoint(15, -13);
	tmp->addPoint(10, -15);
	tmp->addPoint(10, -20);
	tmp->addPoint(10, -25);
	tmp->addPoint(5, -28);
	tmp->addPoint(-5, -28);
	tmp->addPoint(-10, -25);
	tmp->addPoint(-10, -20);
	tmp->addPoint(-10, -15);
	tmp->addPoint(-15, -13);
	tmp->addPoint(-20, -13);
	tmp->addPoint(-25, -10);
	tmp->addPoint(-35, -10);
	tmp->addPoint(-40, -5);
	tmp->addPoint(-40, 5);
	tmp->addPoint(-35, 10);
	
	//Create a BasicEntity as our spaceship.

	this->addLine(tmp);
	delete tmp; // delete when you're done with it.

}

Ufo::~Ufo()
{

}

void Ufo::update(float deltaTime)
{
	
	

	this->line()->color = RED;


}
