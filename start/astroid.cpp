/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "astroid.h"
#include "myscene.h"
#include "collider.h"

Astroid::Astroid() : Entity()
{
	//movement ship


	Line* tmp = new Line();

	tmp->addPoint(0, -20);
	tmp->addPoint(10, -20);
	tmp->addPoint(15, -15);
	tmp->addPoint(15, -5);
	tmp->addPoint(10, 0);
	tmp->addPoint(10, 10);
	tmp->addPoint(5, 15);
	tmp->addPoint(-10, 15);
	tmp->addPoint(-15, 10);
	tmp->addPoint(-15, -10);
	tmp->addPoint(-10, -15);
	tmp->addPoint(0, -20);

	this->addLine(tmp);
	this->line()->color = GRAY;
	this->line()->color.a = 100;
	delete tmp; // delete when you're done with it.

	this->scale = Point(3, 3);

	/*
	Line c1;
	c1.createCircle(33, 18);
	this->addLine(&c1);
	*/
}

Astroid::~Astroid()
{
}

void Astroid::update(float deltaTime)
{
	this->position.y += (1);
	this->line()->color.a = 100;
}