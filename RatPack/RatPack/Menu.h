#include <SFML/Graphics.hpp>
#pragma once
class Menu {
public:
	Menu();
	void openMenu();
	void closeMenu();
	void initialise();
	void render(sf::RenderWindow& t_window);
	void checkIfPressed(sf::Event t_newEvent, sf::RenderWindow& window);
protected:
private:
	bool menuActive;
	//Menu Sprite
	sf::Texture m_menuBgTexture;
	sf::Sprite m_menuBgSprite{ m_menuBgTexture };
	sf::Vector2f m_menuBgPosition;
	//Buttons
	sf::RectangleShape m_startButton;
	sf::Vector2f m_startButtonSize;
	sf::Vector2f m_startButtonPosition;
};