/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <time.h>
#include <ctime>

#include "myscene.h"
#include "bullet.h"
#include "background.h"

float timerCurrent = 0.0f;
float timerTotal = 0.25f;
int spaceshipHealth = 10000;

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	Text* line = new Text();
	Text* line1 = new Text();
	Text* line2 = new Text();
	text.push_back(line);
	text1.push_back(line1);
	text2.push_back(line2);

	
	
	spaceship = new SpaceShip();
	ufo = new Ufo();

	this->addChild(spaceship);
	this->addChild(ufo);
	this->addChild(line);
	this->addChild(line1);
	this->addChild(line2);

	line->scale = Point2(0.5f, 0.5f);
	line->position.x = 30;
	line->position.y = 30;
	line1->scale = Point2(0.5f, 0.5f);
	line1->position.x = SWIDTH - 200;
	line1->position.y = 30;
	line2->scale = Point2(0.5f, 0.5f);
	line2->position.x = 30;
	line2->position.y = SHEIGHT - 30;
	
	
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
	timerCurrent += deltaTime;

	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	srand((unsigned)time(0));

	if (input()->getKey(KeyCode::Space)) {
		Bullet* b = new Bullet();
		b->position = spaceship->position;
		b->rotation = spaceship->rotation;
		addChild(b);
		bullets.push_back(b);
		// Polar to cartesian for force vector!
		Vector2 Force = Vector2(cos(spacer), sin(spacer));
		b->Velocity.y = Force.y * 6;
		b->Velocity.x = Force.x * 6;
	}

	if (timerCurrent >= timerTotal) {
		enemyBullet* b = new enemyBullet();
		b->position = ufo->position;

		addChild(b);
		enemyB.push_back(b);
		// Polar to cartesian for force vector!

		float x1 = spaceship->position.x - ufo->position.x;
		float y1 = spaceship->position.y - ufo->position.y;
		float rotation = atan2(y1, x1);
		b->rotation.z = rotation;
		std::cout << "-";
		Vector2 Force = Vector2(cos(rotation), sin(rotation));
		b->Velocity.y = Force.y * 5;
		b->Velocity.x = Force.x * 5;
		b->rotation.z = rotation;
		timerCurrent -= timerTotal;
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
		if ((dx * dx + dy * dy) <= (radii * radii))
		{
			ufoHealth -= 100;
		}
	}

	for (int i = enemyB.size() - 1; i >= 0; i--) { // backwards!!!
		float dx = enemyB[i]->position.x - spaceship->position.x;
		float dy = enemyB[i]->position.y - spaceship->position.y;
		float radii = enemyB[i]->position.z + UfoR;

		if (enemyB[i]->position.y > SHEIGHT || enemyB[i]->position.y < 0 || enemyB[i]->position.x < 0 || enemyB[i]->position.x > SWIDTH || (dx * dx + dy * dy) <= (radii * radii)) {
			removeChild(enemyB[i]);
			delete enemyB[i]; // delete from the heap first
			enemyB.erase(enemyB.begin() + i); // then, remove from the list
			
		}
		if ((dx * dx + dy * dy) <= (radii * radii))
		{
			spaceshipHealth -= 100;
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

	for (int i = astroids.size() - 1; i < 10; i++)
	{
		Astroid* a = new Astroid();
		a->position.x = 1 + (rand() % SWIDTH);
		a->position.y = 1 + (rand() % SHEIGHT);
		a->rotation.z = 1 + (rand() % 12);
		a->position.y -= SHEIGHT;

		//s->rotation = 1 + (rand() % 3);
		addChild(a);
		astroids.push_back(a);
	}

	for (int i = astroids.size() - 1; i >= 0; i--) { // backwards!!!
		float dx = astroids[i]->position.x - spaceship->position.x;
		float dy = astroids[i]->position.y - spaceship->position.y;
		float radii = astroids[i]->position.z + 62;
		if ((dx * dx + dy * dy) <= (radii * radii)) {
			removeChild(astroids[i]);
			delete astroids[i]; // delete from the heap first
			astroids.erase(astroids.begin() + i); // then, remove from the list
		}
	}

	std::stringstream ufotxt;
	ufotxt << "Health: " << ufoHealth;
	text[0]->message(ufotxt.str(), RED);

	std::stringstream spaceshiptxt;
	spaceshiptxt << "Health: " << spaceshipHealth;
	text1[0]->message(spaceshiptxt.str(), GREEN);

	text2[0]->message("TEST2");
}