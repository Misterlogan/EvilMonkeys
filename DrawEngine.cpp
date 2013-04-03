#include "DrawEngine.h"
#include <Windows.h>

#include <iostream>
using std::cout;

DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeight = ySize;

	cursorVisibility(false);

	map = 0;
}

DrawEngine::~DrawEngine()
{
	cursorVisibility(true);

	gotoxy(0, screenHeight);
}

int DrawEngine::createSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteImage[index] = c;
		return index;
	}
	
	return -1;
}

void DrawEngine::deleteSprite(int index)
{
	//currently not needed
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	gotoxy(posx, posy);
	cout << spriteImage[index];
}

void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	cout << ' ';
}

void DrawEngine::setMap(char** mapData)
{
	map = mapData;
}

void DrawEngine::createBackgroundTile(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		tileImage[index] = c;
	}
}

void DrawEngine::drawBackground()
{
	if (map)
	{
		for (int y = 0; y < screenHeight; y++)
		{
			gotoxy(0, y);
			for (int x = 0; x < screenWidth; x++)
			{
				cout << tileImage[map[x][y]];
			}
		}
	}
}

void DrawEngine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output_handle, pos);
}

void DrawEngine::cursorVisibility(bool visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cciInfo;

	cciInfo.dwSize = 1;
	cciInfo.bVisible = visibility;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &cciInfo);
}