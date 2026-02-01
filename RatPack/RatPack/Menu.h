#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once
class Menu {
public:
	Menu();
	void openMenu();
	void closeMenu();
	void openGameOver();
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
	bool gameOverMenuActive;
	//Menu Sprite
	sf::Texture m_menuBgTexture;
	sf::Sprite m_menuBgSprite{ m_menuBgTexture };
	sf::Vector2f m_menuBgPosition;

	//Menu Sprite
	sf::Texture m_controlBgTexture;
	sf::Sprite m_controlBgSprite{ m_controlBgTexture };
	sf::Vector2f m_controlBgPosition;

	//Menu Sprite
	sf::Texture m_gameOverBgTexture;
	sf::Sprite m_gameOverBgSprite{ m_gameOverBgTexture };
	sf::Vector2f m_gameOverBgPosition;

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


	sf::RectangleShape m_gameOverButton;
	sf::Vector2f m_gameOverButtonSize;
	sf::Vector2f m_gameOverButtonPosition;

};