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
	Position = Vector2(100, 100);
	Line* tmp = new Line();

	tmp->addPoint(5.0f, 0.0f);
	tmp->addPoint(0.0f, 0.0f);
	tmp->addPoint(2.5f, 0.0f);
	tmp->addPoint(2.5f, 2.5f);
	tmp->addPoint(2.5f, -2.5f);

	this->addLine(tmp);
	this->line()->color = WHITE;
	this->line()->color.a = 100;
	delete tmp; // delete when you're done with it.
	this->scale = Point2(0.25, 0.25);
	star = false;
}

Background::~Background()
{
}

void Background::update(float deltaTime)
{
	this->position.x -= (0.05);
	this->position.y += (0.075);
	this->rotation.z += 0.005;
	if (this->scale.x >= 2)
	{
		star = true;
	}
	if (star == false)
	{
		this->scale.x += 0.005;
		this->scale.y += 0.005;
	}

	if (star == true)
	{
		this->scale.x -= 0.005;
		this->scale.y -= 0.005;
	}
	if (this->position.x < 0)
	{
		this->position.x = SWIDTH;
	}
	if (this->position.y > SHEIGHT)
	{
		this->position.y = 0;
	}
}