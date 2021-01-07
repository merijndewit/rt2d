/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"
#include <time.h>
#include "spaceship.h"
#include "collider.h"

Bullet::Bullet() : Entity()
{
	//movement bullet
	Velocity = Vector2(0.0f, 0.0f, 64);
	heading = 0;
	
	//draw bullet
	Line* tmp = new Line();
	tmp->addPoint(14.0f, -0.5f);
	tmp->addPoint(0.0f, 0.0f);
	tmp->addPoint(14.0f, 0.5f);
	tmp->addPoint(0.0f, 1.0f);

	this->addLine(tmp);	
	delete tmp; // delete when you're done with it.	



}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->line()->color = GREEN;
	this->position.y += this->Velocity.y;
	this->position.x += this->Velocity.x;
	Circle circ1 = Circle(this->position.x, this->position.y, 64);
	
	
}
