#ifndef STARTMENU_H
#define STARTMENU_H

#include <rt2d/timer.h>
#include "mainmenu.h"

class startMenu : public MainMenu
{
public:
	startMenu();
	virtual ~startMenu();

	virtual void update(float deltaTime);

	std::vector<Text*> text;
	std::vector<Text*> text2;

private:
	Timer t;
};

#endif /* STARTMENU_H */
