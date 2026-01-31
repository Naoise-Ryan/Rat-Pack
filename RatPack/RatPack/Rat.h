#pragma once

#include "ScreenSize.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Rat
{
public:
	Rat();
	void loadAssets() {}

	void Update(double dt);
	void move(double dt);
	void boundaryCheck();
	void rotate();

	void becomePlayerRat();
	void becomeEnemyRat();

	sf::Sprite getSprite() { return m_sprite; }

protected:
	ScreenSize screen;

	sf::Vector2f m_pos{0.0f, 0.0f};
	float m_speed{ 100.0f };

	const int m_TIME_OF_ROTATION = 150;
	float m_timeOfRotation{ 150.0f };
	const int m_TIME_TILL_ROTATION = 150;
	float m_timeTillRotation{ 150.0f };

	sf::Angle m_rotation{ sf::degrees(0.0f) };
	bool m_rotating = false;
	int m_rotationDir = 0;

	sf::Texture m_Texture;
	sf::Sprite m_sprite{ m_Texture };
};