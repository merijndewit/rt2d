/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.


extern float spacex;
extern float spacey;
extern float spacer;


class SpaceShip : public Entity
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
	
	SpaceShip* spaceship;
	Vector2* Acceleration;
	Vector2* Velocity;
	Vector2* Position;
	Vector2* Force;
	float heading;

private:

};

#endif /* SPACESHIP_H */
