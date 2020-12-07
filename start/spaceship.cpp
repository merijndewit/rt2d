/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <time.h>

#include "spaceship.h"
#include "myentity.h"





void SpaceShip::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
	this->updateSpaceShip(deltaTime);
}

void SpaceShip::updateSpaceShip(float deltaTime)
{
	spaceship->line()->color = WHITE;

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand() % 100) - 50, (rand() % 100) - 50);
	static Polar polar = Polar((rand() % 360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey(KeyCode::Up)) {
		spaceship->line()->color = RED;
		velocity += polar.cartesian() * deltaTime; // thrust
	}
	if (input()->getKey(KeyCode::Right)) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey(KeyCode::Left)) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	spaceship->rotation.z = polar.angle;
	spaceship->position += velocity * deltaTime;

	if (spaceship->position.x < 0) { spaceship->position.x = SWIDTH; }
	if (spaceship->position.x > SWIDTH) { spaceship->position.x = 0; }
	if (spaceship->position.y < 0) { spaceship->position.y = SHEIGHT; }
	if (spaceship->position.y > SHEIGHT) { spaceship->position.y = 0; }
}