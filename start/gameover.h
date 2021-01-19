#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <rt2d/timer.h>
#include "mainmenu.h"

class GameOver : public MainMenu
{
public:
	GameOver();
	virtual ~GameOver();

	virtual void update(float deltaTime);

	std::vector<Text*> text;
	std::vector<Text*> text2;

private:
	Timer t;
};

#endif /* GAMEOVER_H */
