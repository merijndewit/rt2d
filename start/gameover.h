#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <rt2d/timer.h>
#include "mainmenu.h"
#include "myscene.h"

class GameOver : public MainMenu
{
public:
	GameOver();
	virtual ~GameOver();

	virtual void update(float deltaTime);

	std::vector<Text*> text;
	std::vector<Text*> text2;
	std::vector<Text*> text3;
	std::vector<Text*> text4;
	std::vector<Text*> text5;
	std::vector<Text*> text6;
	std::vector<Text*> text7;

private:
	Timer t;
};

#endif /* GAMEOVER_H */
