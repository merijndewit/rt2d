/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class enemyBullet : public Entity
{
public:
	/// @brief Constructor
	enemyBullet();
	/// @brief Destructor
	virtual ~enemyBullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	Vector2 Velocity;
	float heading;

private:

};

#endif /* ENEMYBULLET_H */
