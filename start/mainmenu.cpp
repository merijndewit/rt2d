
#include "mainmenu.h"

int MainMenu::activescene = 0;

MainMenu::MainMenu() : Scene()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	if (input()->getKeyUp(KeyCode::LeftBracket)) {
		activescene--;
	}
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		activescene++;
	}
}