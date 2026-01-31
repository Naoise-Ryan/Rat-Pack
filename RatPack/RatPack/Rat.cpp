#include "Rat.h"

void Rat::move(double dt)
{
	float x = m_sprite.getPosition().x + std::cos(m_rotation.asRadians()) * m_speed * (dt / 1000);
	float y = m_sprite.getPosition().y + std::sin(m_rotation.asRadians()) * m_speed * (dt / 1000);

	m_pos.x = x;
	m_pos.y = y;

	if (m_rotationTimer < 0)
	{
		m_rotating = false;
		m_rotationTimer = 500.0f;
	}

	if (m_pos.x > screen.s_width)
	{
		m_pos.x = screen.s_width;
		m_rotating = true;
		m_rotationDir = rand() % 2;
	}
	else if (m_pos.x < 0)
	{
		m_pos.x = 0;
		m_rotating = true;
		m_rotationDir = rand() % 2;
	}
	if (m_pos.y > screen.s_height)
	{
		m_pos.y = screen.s_height;
		m_rotating = true;
		m_rotationDir = rand() % 2;
	}
	else if (m_pos.y < 0)
	{
		m_pos.y = 0;
		m_rotating = true;
		m_rotationDir = rand() % 2;
	}

	if (m_rotating)
	{
		rotate();
	}

	m_sprite.setPosition(m_pos);
	m_sprite.setRotation(m_rotation);

	std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
}

void Rat::rotate()
{
	if (m_rotationDir == 0)
	{
		m_rotation += sf::degrees(1.0);
		if (m_rotation.asDegrees() == 360.0)
		{
			m_rotation = sf::degrees(0.0f);
		}
	}
	else
	{
		m_rotation -= sf::degrees(1.0);
		if (m_rotation.asDegrees() == 0.0)
		{
			m_rotation = sf::degrees(359.0f);
		}
	}

	m_rotationTimer--;
}

void Rat::becomePlayerRat()
{
}

void Rat::becomeEnemyRat()
{
}
