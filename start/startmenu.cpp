#include <fstream>
#include <sstream>
#include "startmenu.h"
#include "collider.h"
#include "myscene.h"
int clickCounter;
bool controlAssist;
float timer;

startMenu::startMenu() : MainMenu()
{
	t.start();
	Text* line1 = new Text();
	text.push_back(line1);
	this->addChild(line1);

	line1->scale = Point2(0.5f, 0.5f);
	line1->position = Point2(SWIDTH / 2 - 30, 260);

	Text* line2 = new Text();
	text2.push_back(line2);
	this->addChild(line2);

	line2->scale = Point2(0.5f, 0.5f);
	line2->position = Point2(SWIDTH / 2 - 30, 382);

	square1 = new Box();
	square1->position = Point2(SWIDTH/2 - (256/2), 200);
	Line s1;
	s1.addPoint(0, 0);
	s1.addPoint( 256, 0);
	s1.addPoint( 256, 128);
	s1.addPoint( 0, 128);
	s1.addPoint(0, 0);
	square1->addLine(&s1);
	this->addChild(square1);
	square1->scale = Point2(0.0f, 0.0f);

	square2 = new Box();
	square2->position = Point2(SWIDTH / 2 - (256 / 2), 350);
	Line s2;
	s2.addPoint(0, 0);
	s2.addPoint(256, 0);
	s2.addPoint(256, 64);
	s2.addPoint(0, 64);
	s2.addPoint(0, 0);
	square2->addLine(&s2);
	this->addChild(square2);
	clickCounter = 0;
	
	
}

startMenu::~startMenu()
{
}

void startMenu::update(float deltaTime)
{
	MainMenu::update(deltaTime);
	text[0]->message("Play", WHITE);

	Rectangle rect1 = Rectangle(square1->position.x, square1->position.y, 256, 128);
	Rectangle rect2 = Rectangle(square2->position.x, square2->position.y, 256, 64);
	square2->scale = square1->scale;

		
		if (square1->scale.x <= 1)
		{
			square1->scale.x += linear(timer, 0, 2, 1000);
			square1->scale.y += linear(timer, 0, 2, 1000);
			timer++;
		}
	
	//get mouse position
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	// reset colors
	square1->line()->color = GREEN;
	square2->line()->color = RED;
	
	if (Collider::point2rectangle(mouse, rect1)) {
		square1->line()->color = YELLOW;
		if (input()->getMouse(0)) {
			activescene++;
		}
	}

	std::stringstream ditxt;

	if (Collider::point2rectangle(mouse, rect2)) {
		square2->line()->color = MAGENTA;
		if (input()->getMouseDown(0) && clickCounter == 0) {
			clickCounter++;
		}else if (input()->getMouseDown(0) && clickCounter == 1) {
			clickCounter--;
		}
	}
	if (clickCounter == 0)
	{
		ditxt << "Easy", GREEN;
		controlAssist = true;
		spaceshipHealth = 10000;
		timerTotal = 3;
		astroidTotal = 15;
	}
	else if (clickCounter == 1)
	{
		ditxt << "Hard", RED;
		controlAssist = false;
		spaceshipHealth = 8000;
		timerTotal = 1.5;
		astroidTotal = 11;
	}

	text2[0]->message(ditxt.str());


	
	
}