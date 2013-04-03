#ifndef GAME_H
#define GAME_H

#include "DrawEngine.h"
#include "Level.h"
#include "Mage.h"
#include "Character.h"

class Game
{
public:
	bool run();

protected:
	bool getInput(char *c);
	void timerUpdate();
	
private:
	Level* level;
	Mage* player;

	double frameCount;
	double startTime;
	double lastTime;
	
	int posx;

	DrawEngine drawArea;
};

#endif