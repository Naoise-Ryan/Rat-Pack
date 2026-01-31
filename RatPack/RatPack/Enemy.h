#pragma once

#include "Rat.h"

#include <math.h>

class Enemy : Rat
{
public:
	Enemy() { loadAssets(); }
	void loadAssets();

	void enemyUpdate(double dt) { Update(dt); }

	void setSprite(sf::Texture texture);
	sf::Sprite getSprite() { return m_sprite; };

private:
};