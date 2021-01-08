/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "enemyBullet.h"
#include <time.h>
#include "spaceship.h"
#include "collider.h"

enemyBullet::enemyBullet() : Entity()
{
	//movement bullet
	Velocity = Vector2(0.0f, 0.0f, 32);
	heading = 0;
	
	//draw bullet
	Line* tmp = new Line();
	tmp->addPoint(14.0f, -0.5f);
	tmp->addPoint(0.0f, 0.0f);
	tmp->addPoint(14.0f, 0.5f);
	tmp->addPoint(0.0f, 1.0f);

	this->addLine(tmp);	
	delete tmp; // delete when you're done with it.	
	/*
	Line c1;
	c1.createCircle(12, 18);
	this->addLine(&c1);
	*/

}

enemyBullet::~enemyBullet()
{

}

void enemyBullet::update(float deltaTime)
{
	this->line()->color = RED;
	this->position.y += this->Velocity.y;
	this->position.x += this->Velocity.x;

	
	
}
