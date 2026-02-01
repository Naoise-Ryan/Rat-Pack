#include "Player.h"
#include "Game.h"

sf::Texture playerTexture;

void Player::loadAssets()
{
	//if (!m_Texture.loadFromFile("ASSETS\\IMAGES\\playerRat.png"))
	//{
	//	// simple error message if previous call fails
	//	std::cout << "problem loading rat" << std::endl;
	//}

	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\playerRat.png"))
	{
		std::cout << "Problem loading player rat" << std::endl;
	}

	m_sprite.setTexture(playerTexture,true);// to reset the dimensions of texture
	m_sprite.setPosition(m_pos);
}

void Player::rotationInput(const std::optional<sf::Event> t_event)
{
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
}

void Player::move(double dt)
{
	float x = m_sprite.getPosition().x + std::cos(m_rotation.asRadians()) * m_speed * (dt / 1000);
	float y = m_sprite.getPosition().y + std::sin(m_rotation.asRadians()) * m_speed * (dt / 1000);

	m_pos.x = x;
	m_pos.y = y;

	boundaryCheck();

	m_sprite.setPosition(m_pos);
	m_sprite.setRotation(m_rotation);

	//std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
}

void Player::setSprite(sf::Texture texture)
{
	m_sprite.setTexture(m_Texture, true);
}