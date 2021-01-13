#include <fstream>
#include <sstream>
#include "startmenu.h"

startMenu::startMenu() : MainMenu()
{
	t.start();
	Text* line = new Text();
	text.push_back(line);
	this->addChild(line);

	line->scale = Point2(0.5f, 0.5f);
	line->position.x = 30;
	line->position.y = 30;
}

startMenu::~startMenu()
{
}

void startMenu::update(float deltaTime)
{
	MainMenu::update(deltaTime);
	text[0]->message("press ( ] ) to play", MAGENTA);
}