/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef UFO_H
#define UFO_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.

extern float UfoX;
extern float UfoY;
extern float UfoR;

class Ufo : public Entity
{
	

public:
	/// @brief Constructor
	Ufo();
	/// @brief Destructor
	virtual ~Ufo();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	Vector2 Position;
	Ufo* ufo;

private:

};

#endif /* UFO_H */
