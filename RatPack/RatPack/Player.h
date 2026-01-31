#pragma once

#include "Rat.h"

class Player : Rat
{
public:
	Player() {}
	void loadAssets() {}

	void move(const std::optional<sf::Event> t_event)
	{
		const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
		if (sf::Keyboard::Key::W == newKeypress->code || sf::Keyboard::Key::Up == newKeypress->code)
		{
			m_pos.y--;
			std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
		}
		else if (sf::Keyboard::Key::S == newKeypress->code || sf::Keyboard::Key::Down == newKeypress->code)
		{
			m_pos.y++;
			std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
		}
		if (sf::Keyboard::Key::A == newKeypress->code || sf::Keyboard::Key::Right == newKeypress->code)
		{
			m_pos.x++;
			std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
		}
		else if (sf::Keyboard::Key::D == newKeypress->code || sf::Keyboard::Key::Left == newKeypress->code)
		{
			m_pos.x--;
			std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
		}
	}

private:
};