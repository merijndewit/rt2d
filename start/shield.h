/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SHIELD_H
#define SHIELD_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.
class Shield : public Entity
{
public:
	/// @brief Constructor
	Shield();
	/// @brief Destructor
	virtual ~Shield();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	Vector2 Velocity;

private:
};

#endif /* SHIELD_H */
