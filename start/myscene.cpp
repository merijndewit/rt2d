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

float timerCurrent = 0;
float timerTotal;
float astroidTimer = 0.0f;
float astroidTotal = 12;
float ufotimer = 0.0f;
float ufoTotal = 1;
int spaceshipHealth = 1000;
int Points = 0;
int shieldTimer = 0;
int astroidCount = 5;
int ufoTimer = 0;
bool actShield;
bool addUfo;
int astroidpCount = 0;
float astrPosx;
float astrPosy;

int ufohits = 0;
int shieldused = 0;
int bulletsshot = 0;
int astroidsdestroid = 0;
int miniastroidsdestroid = 0;


bool removeAstroid;
bool removeAstroidp;

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

MyScene::MyScene() : MainMenu()
{
	// start the timer.
	t.start();

	Text* line = new Text();
	Text* line1 = new Text();
	Text* line2 = new Text();
	Text* line3 = new Text();
	text.push_back(line);
	text1.push_back(line1);
	text2.push_back(line2);
	text3.push_back(line3);

	spaceship = new SpaceShip();
	ufo = new Ufo();
	shield = new Shield();

	this->addChild(spaceship);
	this->addChild(ufo);

	this->addChild(line);
	this->addChild(line1);
	this->addChild(line2);
	this->addChild(line3);

	line->scale = Point2(0.5f, 0.5f);
	line->position.x = 30;
	line->position.y = 30;
	line1->scale = Point2(0.5f, 0.5f);
	line1->position.x = SWIDTH - 200;
	line1->position.y = 30;
	line2->scale = Point2(0.5f, 0.5f);
	line2->position.x = 30;
	line2->position.y = SHEIGHT - 30;
	line3->scale = Point2(0.5f, 0.5f);
	line3->position.x = SWIDTH / 2;
	line3->position.y = 30;
	timerTotal = 2;
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
	astroidTimer += deltaTime;
	ufotimer += deltaTime;
	MainMenu::update(deltaTime);

	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	if (input()->getKeyUp(KeyCode::Space)) {
		Bullet* b = new Bullet();
		b->position = spaceship->position;
		b->rotation = spaceship->rotation;
		addChild(b);
		bullets.push_back(b);
		// Polar to cartesian for force vector!
		Vector2 Force = Vector2(cos(spacer), sin(spacer));
		b->Velocity.y = Force.y * 6;
		b->Velocity.x = Force.x * 6;
		bulletsshot++;
	}

	if (timerCurrent >= timerTotal && ufoHealth >= 0) {
		enemyBullet* b = new enemyBullet();
		b->position = ufo->position;

		addChild(b);
		enemyB.push_back(b);
		// Polar to cartesian for force vector!

		float x1 = spaceship->position.x - ufo->position.x;
		float y1 = spaceship->position.y - ufo->position.y;
		float rotation = atan2(y1, x1);
		b->rotation.z = rotation;
		Vector2 Force = Vector2(cos(rotation), sin(rotation));
		b->Velocity.y = Force.y * 5;
		b->Velocity.x = Force.x * 5;
		b->rotation.z = rotation;
		timerCurrent -= timerTotal;
	}

	if (astroidTimer >= astroidTotal) {
		astroidTimer -= astroidTotal;
		astroidCount++;
		if (timerTotal >= 0.2)
		{
			timerTotal = timerTotal * 0.95;
		}

	}
	if (ufotimer >= ufoTotal) {
		ufotimer -= ufoTotal;
		ufoTimer -= 1;
		shieldTimer -= 1;
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
			Points += 10;
			ufohits++;
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
		if ((dx * dx + dy * dy) <= (radii * radii) && actShield == false)
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

	for (int i = astroids.size() - 1; i < astroidCount; i++)
	{
		Astroid* a = new Astroid();

		a->position.x = (rand() % SWIDTH);
		a->position.y = (rand() % SHEIGHT);
		a->rotation.z = (rand() % 12);
		a->position.y -= SHEIGHT;

		//s->rotation = 1 + (rand() % 3);
		addChild(a);
		astroids.push_back(a);
	}

	for (int i = astroids.size() - 1; i >= 0; i--) { // backwards!!!
		float am = astroids[i]->position.x;
		float bm = astroids[i]->position.y;
		float dx = astroids[i]->position.x - bulletx;
		float dy = astroids[i]->position.y - bullety;
		float radii = astroids[i]->position.z + 62;
		float sx = astroids[i]->position.x - spaceship->position.x;
		float sy = astroids[i]->position.y - spaceship->position.y;
		float sradii = astroids[i]->position.z + 62;
		for (int i = bullets.size() - 1; i >= 0; i--) { // backwards!!!
			float aa = am - bullets[i]->position.x;
			float bb = bm - bullets[i]->position.y;
			float radii = bullets[i]->position.z + UfoR;
			if ((aa * aa + bb * bb) <= (radii * radii))
			{
				removeAstroid = true;
				removeChild(bullets[i]);
				delete bullets[i]; // delete from the heap first
				bullets.erase(bullets.begin() + i); // then, remove from the list
				Points += 90;
				astroidsdestroid++;
			}
		}

		if (astroids[i]->position.y > SHEIGHT || removeAstroid == true) {
			removeChild(astroids[i]);
			delete astroids[i]; // delete from the heap first
			astroids.erase(astroids.begin() + i); // then, remove from the list
			removeAstroid = false;
			for (int i = 0; i < 4; i++)
			{
				astroidParts* ap = new astroidParts();

				ap->position.x = (am + (rand() % 100));
				ap->position.y = (bm + (rand() % 100));
				ap->rotation.z = (rand() % 12);

				//s->rotation = 1 + (rand() % 3);
				addChild(ap);
				astroidp.push_back(ap);
			}
		
			
		}

		if ((sx * sx + sy * sy) <= (sradii * sradii))
		{
			removeChild(astroids[i]);
			delete astroids[i]; // delete from the heap first
			astroids.erase(astroids.begin() + i); // then, remove from the list
			spaceshipHealth -= 200;
		}
	}

	if (input()->getKeyDown(KeyCode::Q) && shieldTimer <= -60)
	{
		this->addChild(shield);
		shieldTimer = 18;
		actShield = true;
		shieldused++;
	}
	else if (shield && shieldTimer == 0)
	{
		this->removeChild(shield);
		actShield = false;
		
	}

	std::stringstream ufotxt;
	ufotxt << "Health: " << ufoHealth;
	text[0]->message(ufotxt.str(), RED);

	std::stringstream spaceshiptxt;
	spaceshiptxt << "Health: " << spaceshipHealth;
	text1[0]->message(spaceshiptxt.str(), GREEN);

	std::stringstream shieldtxt;

	if (shieldTimer <= -60)
	{
		shieldtxt << "Shield: Ready, Press: Q";
	}
	else if (shieldTimer <= 0)
	{
		shieldtxt << "Shield: Recharging";
	}
	else if (shieldTimer >= 0)
	{
		shieldtxt << "Shield: Active";
	}

	text2[0]->message(shieldtxt.str(), MAGENTA);

	std::stringstream pointstxt;
	pointstxt << "Points: " << Points;
	text3[0]->message(pointstxt.str(), PINK);

	for (int i = astroidp.size() - 1; i >= 0; i--) { // backwards!!!
		float am = astroidp[i]->position.x;
		float bm = astroidp[i]->position.y;
		float dx = astroidp[i]->position.x - bulletx;
		float dy = astroidp[i]->position.y - bullety;
		float radii = astroidp[i]->position.z + 62;
		float sx = astroidp[i]->position.x - spaceship->position.x;
		float sy = astroidp[i]->position.y - spaceship->position.y;
		float sradii = astroidp[i]->position.z + 62;
		for (int i = bullets.size() - 1; i >= 0; i--) { // backwards!!!
			float aa = am - bullets[i]->position.x;
			float bb = bm - bullets[i]->position.y;
			float radii = bullets[i]->position.z + 20;
			if ((aa * aa + bb * bb) <= (radii * radii))
			{
				removeAstroidp = true;
				removeChild(bullets[i]);
				delete bullets[i]; // delete from the heap first
				bullets.erase(bullets.begin() + i); // then, remove from the list
				Points += 30;
				miniastroidsdestroid++;
			}
		}

		if (astroidp[i]->position.y > SHEIGHT || removeAstroidp == true) {
			removeChild(astroidp[i]);
			delete astroidp[i]; // delete from the heap first
			astroidp.erase(astroidp.begin() + i); // then, remove from the list
			removeAstroidp = false;
			
		}
		if ((sx * sx + sy * sy) <= (sradii * sradii))
		{
			removeChild(astroidp[i]);
			delete astroidp[i]; // delete from the heap first
			astroidp.erase(astroidp.begin() + i); // then, remove from the list
			spaceshipHealth -= 25;
		}
	}
	if (ufoHealth <= 0 && addUfo == false)
	{
		removeChild(ufo);
		ufoTimer = 30;
		addUfo = true;
	}

	if ((ufoTimer <= 0) && (addUfo == true))
	{
		timerCurrent = 0;
		addUfo = false;
		ufoHealth = 10000;
		addChild(ufo);
	}

	if (spaceshipHealth <= 0)
	{
		activescene++;
	}
}