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
#include "shield.h"
#include "mainmenu.h"
#include "astroidparts.h"

extern float astrPosx;
extern float astrPosy;
/// @brief The MyScene class is the Scene implementation.
class MyScene : public MainMenu
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
	Shield* shield;

	unsigned int top_layer;
	std::vector<Entity*> layers;
	std::vector<Bullet*> bullets;
	std::vector<enemyBullet*> enemyB;
	std::vector<Background*> stars;
	std::vector<Astroid*> astroids;
	std::vector<Text*> text;
	std::vector<Text*> text1;
	std::vector<Text*> text2;
	std::vector<Text*> text3;
	std::vector<astroidParts*> astroidp;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* MYSCENE_H */
