#include <iostream>
#include "Menu.h"
Menu::Menu() {
	menuActive = false;
	//Size Dimensions
	m_startButtonSize = { 100, 100 };
	m_startButtonPosition = { 100, 100 };
	m_menuBgPosition = { 0.0f, 0.0f };
}

void Menu::openMenu()
{
	menuActive = true;
}
void Menu::closeMenu()
{
	menuActive = false;
}
void Menu::initialise()
{
	//Start Button
	m_startButton.setFillColor(sf::Color::White);
	m_startButton.setSize(m_startButtonSize);
	m_startButton.setPosition(m_startButtonPosition);

	if (!m_menuBgTexture.loadFromFile("ASSETS\\IMAGES\\menu_image.png")) {
		std::cout << "Problem loading bg sprite" << std::endl;
	}
	m_menuBgSprite.setTexture(m_menuBgTexture,true);// to reset the dimensions of texture
	m_menuBgSprite.setPosition(m_menuBgPosition);
}

void Menu::render(sf::RenderWindow& t_window)
{
	if (menuActive) {
		t_window.draw(m_menuBgSprite);
		t_window.draw(m_startButton);
	}
}

void Menu::checkIfPressed(sf::RenderWindow& window)
{
	// Get mouse position in pixels relative to the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	sf::Vector2f mousePosWindow = window.mapPixelToCoords(pixelPos);

	if (menuActive) {
		sf::FloatRect startButtonZone = m_startButton.getGlobalBounds();

		if (startButtonZone.contains(mousePosWindow)) {
			std::cout << "a";
		}
	}
}