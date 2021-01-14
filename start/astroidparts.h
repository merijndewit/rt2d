/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ASTROIDPARTS_H
#define ASTROIDPARTS_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.

class astroidParts : public Entity
{
public:
	/// @brief Constructor
	astroidParts();
	/// @brief Destructor
	virtual ~astroidParts();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	Vector2 Position;
	Vector2 Velocity;
	astroidParts* astroidparts;

private:
};

#endif /* ASTROIDPARTS_H */
