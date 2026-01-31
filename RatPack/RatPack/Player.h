#pragma once

#include "Rat.h"

#include <math.h>

class Player : Rat
{
public:
	Player() { loadAssets(); }
	void loadAssets();

	void rotationInput(const std::optional<sf::Event> t_event);
	void move(double dt);

	sf::Sprite getSprite() { return m_sprite; }

private:
};