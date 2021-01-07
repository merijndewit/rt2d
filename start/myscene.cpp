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
#include "background.h"


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
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	srand((unsigned)time(0));

	if (input()->getKeyUp(KeyCode::Space)) {
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
		float dx = bullets[i]->position.x - ufo->position.x;
		float dy = bullets[i]->position.y - ufo->position.y;
		float radii = bullets[i]->position.z + UfoR;
		if (bullets[i]->position.y > SHEIGHT || bullets[i]->position.y < 0 || bullets[i]->position.x < 0 || bullets[i]->position.x > SWIDTH || (dx * dx + dy * dy) <= (radii * radii)) {
			removeChild(bullets[i]);
			delete bullets[i]; // delete from the heap first
			bullets.erase(bullets.begin() + i); // then, remove from the list
		}
	}
	for (int i = stars.size() - 1; i < 100; i++)
	{
		Background* s = new Background();
		s->position.x = 1 + (rand() % SWIDTH);
		s->position.y = 1 + (rand() % SHEIGHT);
		s->rotation.z = 1 + (rand() % 12);
		
		//s->rotation = 1 + (rand() % 3);
		addChild(s);
		stars.push_back(s);
	}





}



