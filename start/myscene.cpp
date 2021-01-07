/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <time.h>

#include "myscene.h"
#include "bullet.h"


RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	spaceship = new SpaceShip();
	ufo = new Ufo();

	this->addChild(spaceship);
	this->addChild(ufo);


}


MyScene::~MyScene()
{
	
	
	this->removeChild(spaceship);
	this->removeChild(ufo);

	
	delete spaceship;
	delete ufo;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}


	if (input()->getKeyDown(KeyCode::Space)) {
		Bullet* b = new Bullet();
		b->position = spaceship->position;
		b->rotation = spaceship->rotation;
		addChild(b);
		bullets.push_back(b);
		// Polar to cartesian for force vector!
		Vector2 Force = Vector2(cos(spacer), sin(spacer));
		b->Velocity.y = Force.y * 10;
		b->Velocity.x = Force.x * 10;
	}

	for (int i = bullets.size() - 1; i >= 0; i--) { // backwards!!!
		if (bullets[i]->position.y > SHEIGHT || bullets[i]->position.y < 0 || bullets[i]->position.x < 0 || bullets[i]->position.x > SWIDTH) {
			removeChild(bullets[i]);
			delete bullets[i]; // delete from the heap first
			bullets.erase(bullets.begin() + i); // then, remove from the list
			
		}
	}
	for (int i = bullets.size() - 1; i >= 0; i--) { // backwards!!!
		float dx = bullets[i]->position.x - 100;
		float dy = bullets[i]->position.y - 100;
		float radii = bullets[i]->position.z + 200;
		if ((dx * dx + dy * dy) < (radii * radii))
		{
			removeChild(bullets[i]);
			delete bullets[i]; // delete from the heap first
			bullets.erase(bullets.begin() + i); // then, remove from the list
		}
	}
}



