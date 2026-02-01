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

	void setPosition(sf::Vector2f t_pos) { m_pos = t_pos; }

	void setSprite(sf::Texture texture);
	sf::Sprite getSprite() { return m_sprite; }

private:
};