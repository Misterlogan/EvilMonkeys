#ifndef LEVEL_H
#define LEVEL_H

#include <list>
using std::list;

enum
{
	SPRITE_PLAYER,
	SPRITE_ENEMY,
	SPRITE_FIREBALL
};

enum
{
	TILE_EMPTY,
	TILE_WALL
};

#include "DrawEngine.h"

class Sprite;
class Character;

class Level
{
public:
	Level(DrawEngine* de, int width = 30, int height = 20);
	~Level();

	void addPlayer(Character* p);
	void update();
	void draw();
	bool keyPress(char c);

	void addEnemies(int num);
	void addNPC(Sprite* spr);

	friend class Sprite;

protected:
	void createLevel();

private:
	int width;
	int height;

	char** level;

	Character* player;
	DrawEngine* drawArea;

public:
	list <Sprite*> npc;
	list <Sprite*>::iterator Iter;


};

#endif