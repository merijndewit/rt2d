/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "spaceship.h"
#include "myscene.h"

int spacex;
int spacey;
int spacer;




SpaceShip::SpaceShip() : Entity()
{
	//movement ship
	Position = new Vector2(SWIDTH/2,SHEIGHT/2);
	Velocity = new Vector2(0.0f, 0.0f);
	Acceleration = new Vector2(0, -3);
	heading = 0;
	
	Line* tmp = new Line();
	tmp->addPoint(-10.0f, -10.0f);
	tmp->addPoint(20.0f, 0.0f);
	tmp->addPoint(-10.0f, 10.0f);
	tmp->addPoint(-10.0f, -10.0f);

	//Create a BasicEntity as our spaceship.
	
	this->addLine(tmp);
	this->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	delete tmp; // delete when you're done with it.
	
	
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::update(float deltaTime)
{
	
	this->line()->color = BLUE;

	float rotspeed = 3.14f;

	//static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Up)) {
		this->line()->color = RED;
		
		float angle = heading - PI / 2;
		// Polar to cartesian for force vector!
		Force = new Vector2(cos(polar.angle), sin(polar.angle));
		this->position.y += this->Velocity->y = Force->y * 100 * deltaTime;

		this->position.x += this->Velocity->x = Force->x * 100 * deltaTime;
	}
	if (input()->getKey(KeyCode::Right)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::Left)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	this->rotation.z = polar.angle;
	//this->position += velocity * deltaTime;

	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }
	spacex = this->position.x;
	spacey = this->position.y;
	spacer = this->rotation.z;
	
	
	
}
