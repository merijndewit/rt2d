#ifndef STARTMENU_H
#define STARTMENU_H

#include <rt2d/timer.h>
#include "mainmenu.h"
#include "myscene.h"
#include <math.h>

extern bool controlAssist;

class startMenu : public MainMenu
{
public:
	startMenu();
	virtual ~startMenu();

	virtual void update(float deltaTime);

	std::vector<Text*> text;
	std::vector<Text*> text2;

	float linear(float t, float b, float c, float d) {
		return -c / 2 * (cos(PI * t / d) - 1) + b;

	}
	
private:
	Timer t;
};

#endif /* STARTMENU_H */
