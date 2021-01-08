/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ASTROID_H
#define ASTROID_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.

class Astroid : public Entity
{
public:
	/// @brief Constructor
	Astroid();
	/// @brief Destructor
	virtual ~Astroid();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	Vector2 Position;
	Vector2 Velocity;
	Astroid* astroid;

private:
};

#endif /* ASTROID_H */
