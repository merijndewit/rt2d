#ifndef MAINMENU_H
#define MAINMENU_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/text.h>

class MainMenu : public Scene
{
public:
	MainMenu();
	virtual ~MainMenu();

	// must be explicitly called from subclass
	virtual void update(float deltaTime);

	static int activescene;
};

#endif /* MAINMENU_H */
