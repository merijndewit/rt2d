#include <rt2d/core.h>

#include "startmenu.h"
#include "myscene.h"
#include "gameover.h"

int main(void)
{
	Core core;

	std::vector<MainMenu*> scenes;
	scenes.push_back(new startMenu());
	scenes.push_back(new MyScene());
	scenes.push_back(new GameOver());
	int s = scenes.size();

	MainMenu* scene = scenes[0];
	int scenecounter = 0;
	int running = 1;
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s - 1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s - 1; scene->activescene = s - 1; }
		scene = scenes[scenecounter];
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}

	for (int i = 0; i < s; i++) {
		delete scenes[i];
		scenes[i] = nullptr;
	}
	scenes.clear();

	return 0;
}