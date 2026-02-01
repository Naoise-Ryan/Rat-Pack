#pragma once

#include "Rat.h"

#include <math.h>

class Enemy : Rat
{
public:
	Enemy() { loadAssets(); }
	void loadAssets();

	void enemyUpdate(double dt) { Update(dt); }

	void setPosition(sf::Vector2f t_pos) { m_pos = t_pos; }

	void setSprite(sf::Texture texture);
	sf::Sprite getSprite() { return m_sprite; };

private:
};