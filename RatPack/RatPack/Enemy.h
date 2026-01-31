#pragma once

#include "Rat.h"

#include <math.h>

class Enemy : Rat
{
public:
	Enemy() { loadAssets(); }
	void loadAssets();

	void enemyMove(double dt) { move(dt); }

	sf::Sprite getSprite() { return m_sprite; }

private:
};