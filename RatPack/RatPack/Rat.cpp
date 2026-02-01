#include "Rat.h"

Rat::Rat()
{
	int startRotation = rand() % 360;
	m_sprite.setRotation(sf::Angle(sf::degrees(startRotation)));

	m_pos.x = rand() % screen.s_width;
	m_pos.y = rand() % screen.s_height;
}

void Rat::loadAssets()
{
	//if (!m_Texture.loadFromFile("ASSETS\\IMAGES\\rat.png"))
	//{
	//	// simple error message if previous call fails
	//	std::cout << "problem loading rat" << std::endl;
	//}

	m_sprite.setTexture(m_Texture, true);// to reset the dimensions of texture
	m_sprite.setPosition(m_pos);

	m_timeTillRotation = rand() % m_TIME_TILL_ROTATION;

	int startRotation = rand() % 360;
	m_sprite.setRotation(sf::Angle(sf::degrees(startRotation)));

	m_pos.x = rand() % screen.s_width;
	m_pos.y = rand() % screen.s_height;
}

void Rat::Update(double dt)
{
	move(dt);
	boundaryCheck();

	if (m_timeOfRotation < 0)
	{
		m_rotating = false;
		m_timeOfRotation = m_TIME_OF_ROTATION;
	}

	if (m_rotating)
	{
		rotate();
	}

	if (m_timeTillRotation < 0)
	{
		m_rotating = true;
		m_timeTillRotation = m_TIME_TILL_ROTATION;
	}

	m_timeTillRotation--;
}

void Rat::move(double dt)
{
	float x = m_sprite.getPosition().x + std::cos(m_rotation.asRadians()) * m_speed * (dt / 1000);
	float y = m_sprite.getPosition().y + std::sin(m_rotation.asRadians()) * m_speed * (dt / 1000);

	m_pos.x = x;
	m_pos.y = y;

	m_sprite.setPosition(m_pos);

	//std::cout << "x: " << m_pos.x << " y: " << m_pos.y << "\n";
}

void Rat::boundaryCheck()
{
	if (m_pos.x > screen.s_width)
	{
		m_pos.x = screen.s_width;
		if (!m_rotating)
		{
			m_rotating = true;
			m_rotationDir = rand() % 2;
		}
	}
	else if (m_pos.x < 0)
	{
		m_pos.x = 0;
		if (!m_rotating)
		{
			m_rotating = true;
			m_rotationDir = rand() % 2;
		}
	}
	if (m_pos.y > screen.s_height)
	{
		m_pos.y = screen.s_height;
		if (!m_rotating)
		{
			m_rotating = true;
			m_rotationDir = rand() % 2;
		}
	}
	else if (m_pos.y < 0)
	{
		m_pos.y = 0;
		if (!m_rotating)
		{
			m_rotating = true;
			m_rotationDir = rand() % 2;
		}
	}
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

	m_timeOfRotation--;
	m_sprite.setRotation(m_rotation);
}