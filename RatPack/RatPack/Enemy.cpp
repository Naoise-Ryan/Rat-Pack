#include "Enemy.h"

void Enemy::loadAssets()
{
	//if (!m_Texture.loadFromFile("ASSETS\\IMAGES\\enemyRat.png"))
	//{
	//	// simple error message if previous call fails
	//	std::cout << "problem loading rat" << std::endl;
	//}

	m_sprite.setTexture(m_Texture, true);// to reset the dimensions of texture
	m_sprite.setPosition(m_pos);
}

void Enemy::setSprite(sf::Texture texture)
{
	m_sprite.setTexture(m_Texture, true);
}