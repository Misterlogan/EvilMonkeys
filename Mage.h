#ifndef MAGE_H
#define MAGE_H

#include "DrawEngine.h"
#include "Character.h"


class Mage : public Character
{
public:
	Mage(Level* l, DrawEngine* de, int s_index, float x = 1, float y = 1, int lives = 3, 
		char spell_key = ' ', char up_key = 'w', char down_key = 's', char left_key = 'a', char right_key = 'd');
	
	bool keyPress(char c);

protected:
	void castSpell();

private:
	char spellKey;

};

#endif