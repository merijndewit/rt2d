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
	line2->position = Point2(SWIDTH / 2 - 30, 280);

	Text* line3 = new Text();
	text3.push_back(line3);
	this->addChild(line3);
	line3->scale = Point2(0.5f, 0.5f);
	line3->position = Point2(SWIDTH / 2 - 30, 300);

	Text* line4 = new Text();
	text4.push_back(line4);
	this->addChild(line4);
	line4->scale = Point2(0.5f, 0.5f);
	line4->position = Point2(SWIDTH / 2 - 30, 320);

	Text* line5 = new Text();
	text5.push_back(line5);
	this->addChild(line5);
	line5->scale = Point2(0.5f, 0.5f);
	line5->position = Point2(SWIDTH / 2 - 30, 340);

	Text* line6 = new Text();
	text6.push_back(line6);
	this->addChild(line6);
	line6->scale = Point2(0.5f, 0.5f);
	line6->position = Point2(SWIDTH / 2 - 30, 360);

	Text* line7 = new Text();
	text7.push_back(line7);
	this->addChild(line7);
	line7->scale = Point2(0.5f, 0.5f);
	line7->position = Point2(SWIDTH / 2 - 30, 380);

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
	std::stringstream pointstxt;
	pointstxt << "Points: " << Points;
	text2[0]->message(pointstxt.str(), PINK);

	std::stringstream atxt;
	atxt << "Astroids Destroid: " << astroidsdestroid;
	text3[0]->message(atxt.str(), PINK);

	std::stringstream mtxt;
	mtxt << "Miniastroids Destroid: " << miniastroidsdestroid;
	text4[0]->message(mtxt.str(), PINK);

	std::stringstream btxt;
	btxt << "Bullets Shot: " << bulletsshot;
	text5[0]->message(btxt.str(), PINK);

	std::stringstream utxt;
	utxt << "Ufo Hits: " << ufohits;
	text6[0]->message(utxt.str(), PINK);

	std::stringstream stxt;
	stxt << "Shield Used: " << shieldused;
	text7[0]->message(stxt.str(), PINK);
}