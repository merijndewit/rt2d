/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <rt2d/text.h>

#include "spaceship.h"
#include "bullet.h"
#include "ufo.h"
#include "background.h"
#include "enemyBullet.h"
#include "astroid.h"


/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	
	
private:
	/// @brief the rotating square in the middle of the screen
	
	SpaceShip* spaceship;
	Ufo* ufo;
	
	//Bullet* bullet;
	std::vector<Bullet*> bullets;
	std::vector<enemyBullet*> enemyB;
	std::vector<Background*> stars;
	std::vector<Astroid*> astroids;

	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
