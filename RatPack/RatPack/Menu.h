#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once
class Menu {
public:
	Menu();
	void openMenu();
	void closeMenu();
	void initialise();
	void render(sf::RenderWindow& t_window);
	void checkIfPressed(sf::RenderWindow& window);
	bool isMenuActive();


	sf::Music m_music1;
	sf::Music m_music2;
	void Music1();
	void Music2();
protected:
private:
	bool menuActive;
	bool controlMenuActive;
	//Menu Sprite
	sf::Texture m_menuBgTexture;
	sf::Sprite m_menuBgSprite{ m_menuBgTexture };
	sf::Vector2f m_menuBgPosition;

	//Menu Sprite
	sf::Texture m_controlBgTexture;
	sf::Sprite m_controlBgSprite{ m_controlBgTexture };
	sf::Vector2f m_controlBgPosition;

	//Buttons
	sf::RectangleShape m_startButton;
	sf::Vector2f m_startButtonSize;
	sf::Vector2f m_startButtonPosition;

	sf::RectangleShape m_controlButton;
	sf::Vector2f m_controlsButtonSize;
	sf::Vector2f m_controlsButtonPosition;

	sf::RectangleShape m_exitButton;
	sf::Vector2f m_exitButtonSize;
	sf::Vector2f m_exitButtonPosition;

	sf::RectangleShape m_goBackButton;
	sf::Vector2f m_goBackButtonSize;
	sf::Vector2f m_goBackButtonPosition;

};