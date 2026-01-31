#include "Player.h"

void Player::loadAssets()
{
	if (!m_Texture.loadFromFile("ASSETS\\IMAGES\\playerRat.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading rat" << std::endl;
	}
	
	m_sprite.setTexture(m_Texture,true);// to reset the dimensions of texture
	m_sprite.setPosition(m_pos);
}

void Player::move(const std::optional<sf::Event> t_event, double dt)
{
	float x = m_sprite.getPosition().x + std::cos(m_rotation.asRadians()) * m_speed * (dt / 1000);
	float y = m_sprite.getPosition().y + std::sin(m_rotation.asRadians()) * m_speed * (dt / 1000);

	m_pos.x = x;
	m_pos.y = y;

	const sf::Event::KeyPressed* newKeypress = t_event->getIf<sf::Event::KeyPressed>();
	if (sf::Keyboard::Key::A == newKeypress->code || sf::Keyboard::Key::Right == newKeypress->code)
	{
		m_rotation += sf::degrees(1.0);
		if (m_rotation.asDegrees() == 360.0)
		{
			m_rotation = sf::degrees(0.0f);
		}
	}
	else if (sf::Keyboard::Key::D == newKeypress->code || sf::Keyboard::Key::Left == newKeypress->code)
	{
		m_rotation -= sf::degrees(1.0);
		if (m_rotation.asDegrees() == 0.0)
		{
			m_rotation = sf::degrees(359.0f);
		}
	}

	if (m_pos.x > screen.s_width)
	{
		m_pos.x = screen.s_width;
	}
	else if (m_pos.x < 0)
	{
		m_pos.x = 0;
	}
	if (m_pos.y > screen.s_height)
	{
		m_pos.y = screen.s_height;
	}
	else if (m_pos.y < 0)
	{
		m_pos.y = 0;
	}

	m_sprite.setPosition(m_pos);
	m_sprite.setRotation(m_rotation);

	std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
}