#include <fstream>
#include <sstream>
#include "gameover.h"
#include "collider.h"


GameOver::GameOver() : MainMenu()
{
	t.start();
	Text* line1 = new Text();
	text.push_back(line1);
	this->addChild(line1);

	line1->scale = Point2(0.5f, 0.5f);
	line1->position = Point2(SWIDTH / 2 - 30, 160);

	Text* line2 = new Text();
	text2.push_back(line2);
	this->addChild(line2);

	line2->scale = Point2(0.5f, 0.5f);
	line2->position = Point2(SWIDTH / 2 - 30, 382);

	square1 = new Box();
	square1->position = Point2(SWIDTH / 2 - (256 / 2), 100);
	Line s1;
	s1.addPoint(0, 0);
	s1.addPoint(256, 0);
	s1.addPoint(256, 128);
	s1.addPoint(0, 128);
	s1.addPoint(0, 0);
	square1->addLine(&s1);
	this->addChild(square1);
}

GameOver::~GameOver()
{
}

void GameOver::update(float deltaTime)
{
	MainMenu::update(deltaTime);
	text[0]->message("Back", WHITE);

	Rectangle rect1 = Rectangle(square1->position.x, square1->position.y, 256, 128);

	//get mouse position
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	// reset colors
	square1->line()->color = GREEN;

	if (Collider::point2rectangle(mouse, rect1)) {
		square1->line()->color = YELLOW;
		if (input()->getMouse(0)) {
			activescene = 0;
		}
	}



}