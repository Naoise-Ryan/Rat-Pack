#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Rat
{
public:
	Rat() {}
	virtual void loadAssets() {}

	virtual void move() {}

protected:
	sf::Vector2f m_pos{200.0f, 200.0f};
};