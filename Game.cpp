// Game.cpp

#include "Game.h"
#include "drawEngine.h"

#include <Windows.h>

#include <conio.h>
#include <iostream>

using std::cout;
using std::endl;

#define GAME_SPEED 33.33

bool Game::run()
{	
	level = new Level(&drawArea, 30, 20);

	drawArea.createBackgroundTile(TILE_EMPTY, ' ');
	drawArea.createBackgroundTile(TILE_WALL, 219);

	drawArea.createSprite(SPRITE_PLAYER, '1');
	drawArea.createSprite(SPRITE_ENEMY, '$');
	drawArea.createSprite(SPRITE_FIREBALL, '*');

	player = new Mage(level, &drawArea, 0);
	

	level->draw();
	level->addPlayer(player);
	level->addEnemies(3);
	
	char key = ' ';

	startTime = timeGetTime();
	frameCount = 0;	
	lastTime = 0;
	
	posx = 0;

	player->move(0,0);

	while(key != 'q')
	{
		while(!getInput(&key))
		{
			timerUpdate();
		}

		level->keyPress(key);
	}

	delete player;

	//cout << frameCount/((timeGetTime() - startTime)/1000) << " fps" << endl;
	return true;
}


bool Game::getInput(char* c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true;
	}
	return false;
}

void Game::timerUpdate()
{
	double currentTime = timeGetTime() - lastTime;

	if(currentTime < GAME_SPEED)
	{
		return;
	}

	level->update();

	frameCount++;

	lastTime = timeGetTime();
}