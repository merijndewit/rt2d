/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "background.h"
#include "myscene.h"
#include "collider.h"



Background::Background() : Entity()
{
	//movement ship

	Position = Vector2(100, 100);
	Line* tmp = new Line();

	tmp->addPoint(5.0f, 0.0f);
	tmp->addPoint(0.0f, 0.0f);
	tmp->addPoint(2.5f, 0.0f);
	tmp->addPoint(2.5f, 2.5f);
	tmp->addPoint(2.5f, -2.5f);
	
	this->addLine(tmp);
	delete tmp; // delete when you're done with it.
	this->position = Point2(500, 500);

}

Background::~Background()
{

}

void Background::update(float deltaTime)
{
	this->line()->color = WHITE;

}
