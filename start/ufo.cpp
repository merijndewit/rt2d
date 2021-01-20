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
#include "collider.h"

float UfoX;
float UfoY;
float UfoR;

int ufoHealth;

bool pos;

Ufo::Ufo() : Entity()
{
	ufoHealth = 10000;

	Position = Vector2(100, 100, 45);
	Line* tmp = new Line();
	tmp->addPoint(-35, 10);
	tmp->addPoint(-15, 10);
	tmp->addPoint(-10, 12);
	tmp->addPoint(10, 12);
	tmp->addPoint(15, 10);
	tmp->addPoint(35, 10);
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

	this->addLine(tmp);
	delete tmp; // delete when you're done with it.
	this->position = Point2(160, 90);
	/* uncomment for visual collision
	Line c1;
	c1.createCircle(45, 18);
	this->addLine(&c1);
	*/
	pos = false;
}

Ufo::~Ufo()
{
}

void Ufo::update(float deltaTime)
{
	this->line()->color = RED;

	UfoR = this->Position.z;

	float dx = this->position.x - spacex;
	float dy = this->position.y - spacey;
	float radii = 300;

	if ((dx * dx + dy * dy) <= (radii * radii))
	{
		if (pos == false)
		{
			this->position = Point2(1100, 650);
			pos = true;
		}
		else if (pos == true)
		{
			this->position = Point2(100, 100);
			pos = false;
		}
	}
}