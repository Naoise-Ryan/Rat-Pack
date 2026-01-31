#include <SFML/Graphics.hpp>
#pragma once
class Menu {
public:
	Menu();
	void openMenu();
	void initialise();
	void render(sf::RenderWindow& t_window);
protected:
private:
	bool menuActive;
	//Buttons
	sf::RectangleShape m_startButton;
	sf::Vector2f m_startButtonSize;
	sf::Vector2f m_startButtonPosition;
	//Funcs
	void setupFontAndText();
	void checkIfPressed(sf::Event t_newEvent, sf::RenderWindow& window);
};