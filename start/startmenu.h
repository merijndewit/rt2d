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

		if ((t /= d) < (1 / 2.75f)) {
			return c * (7.5625f * t * t) + b;
		}
		else if (t < (2 / 2.75f)) {
			float postFix = t -= (1.5f / 2.75f);
			return c * (7.5625f * (postFix)*t + .75f) + b;
		}
		else if (t < (2.5 / 2.75)) {
			float postFix = t -= (2.25f / 2.75f);
			return c * (7.5625f * (postFix)*t + .9375f) + b;
		}
		else {
			return c;
		}
	}
	
private:
	Timer t;
};

#endif /* STARTMENU_H */
