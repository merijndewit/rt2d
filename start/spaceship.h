/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <rt2d/scene.h>

#include "myentity.h"

 /// @brief The MyScene class is the Scene implementation.
class SpaceShip : public Scene
{
public:
	/// @brief Constructor
	SpaceShip();
	/// @brief Destructor
	virtual ~SpaceShip();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	MyEntity* spaceship;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	void updateSpaceShip(float deltaTime);
};

#endif /* SCENE00_H */