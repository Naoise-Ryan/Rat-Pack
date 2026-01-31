#pragma once

#include "ScreenSize.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Rat
{
public:
	Rat() { loadAssets(); }
	void loadAssets() {}

	void move(double dt);
	void rotate();

	void becomePlayerRat();
	void becomeEnemyRat();

	sf::Sprite getSprite() { return m_sprite; }

protected:
	ScreenSize screen;

	sf::Vector2f m_pos{0.0f, 0.0f};
	float m_speed{ 600.0f };

	sf::Angle m_rotation{ sf::degrees(0.0f) };
	float m_rotationTimer{ 150.0f };
	bool m_rotating = false;
	int m_rotationDir = 0;

	sf::Texture m_Texture;
	sf::Sprite m_sprite{ m_Texture };
};