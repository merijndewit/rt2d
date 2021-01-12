/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "shield.h"
#include <time.h>
#include "spaceship.h"
#include "collider.h"

Shield::Shield() : Entity()
{
	Line c1;
	c1.createCircle(26, 18);
	this->scale = Point2(0, 0);
	this->addLine(&c1);
	this->line()->color = MAGENTA;
}

Shield::~Shield()
{
}

void Shield::update(float deltaTime)
{
	if (this->scale.x <= 1)
	{
		this->scale += Point2(0.03, 0.03);
	}
	this->position.y = spacey;
	this->position.x = spacex;
}