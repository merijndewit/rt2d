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
	
	this->addLine(&c1);
	this->line()->color = BLUE;

}

Shield::~Shield()
{

}

void Shield::update(float deltaTime)
{
	
	this->position.y = spacey;
	this->position.x = spacex;

	
	
}
