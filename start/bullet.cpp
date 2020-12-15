/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"
#include <time.h>
#include "spaceship.h"

Bullet::Bullet() : Entity()
{
	

	Line* tmp = new Line();
	tmp->addPoint(-10.0f, -10.0f);
	tmp->addPoint(0.0f, 0.0f);
	

	//Create a BasicEntity as our spaceship.

	this->addLine(tmp);
	
	delete tmp; // delete when you're done with it.
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->line()->color = GREEN;
	
	this->rotation.z = spacer;

	this->line()->color = BLUE;

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKeyDown(KeyCode::Space)) {
		this->line()->color = RED;
		velocity += polar.cartesian() * deltaTime; // thrust
	}
	this->position += velocity * deltaTime;

}
