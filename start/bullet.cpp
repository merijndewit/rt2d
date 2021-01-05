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
	Position = new Vector2(SWIDTH / 2, SHEIGHT / 2);
	Velocity = new Vector2(0.0f, 0.0f);
	Acceleration = new Vector2(0, -3);
	heading = 0;
	

	Line* tmp = new Line();
	tmp->addPoint(10.0f, 0.0f);
	tmp->addPoint(0.0f, 0.0f);
	

	//Create a BasicEntity as our spaceship.

	this->addLine(tmp);
	
	delete tmp; // delete when you're done with it.
	
	
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	this->line()->color = GREEN;
	
	this->rotation.z = spacer;
	
	this->position.y += this->Velocity->y;
	this->position.x += this->Velocity->x;

	this->line()->color = BLUE;

	float rotspeed = 3.14f;

	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Space)) {
		this->position = Point2(spacex, spacey);

		float angle = heading - PI / 2;
		// Polar to cartesian for force vector!
		Force = new Vector2(cos(spacer), sin(spacer));
		this->Velocity->y = Force->y * 10;
		
		this->Velocity->x = Force->x * 10;
		
	}
	

	//this->position += velocity * deltaTime;

	if (this->position.x < 0)
	{
		this->position.x = 0;
		this->Acceleration->x = 0;
	}
	if (this->position.x > SWIDTH)
	{
		this->position.x = SWIDTH;
		this->Acceleration->x = 0;
	}
	if (this->position.y < 0)
	{
		this->position.y = 0;
		this->Acceleration->y = 0;
	}
	if (this->position.y > SHEIGHT)
	{
		this->Acceleration->y = 0;
		this->position.y = SHEIGHT;
	}
}
