#include <iostream>
#include "Menu.h"
Menu::Menu() {
	menuActive = true;
	//Size Dimensions
	m_startButtonSize = { 250, 80 };
	m_startButtonPosition = { 282, 425 };

	m_controlsButtonSize = { 200, 80 };
	m_controlsButtonPosition = { 134, 586 };

	m_exitButtonSize = { 200, 80 };
	m_exitButtonPosition = { 426, 571 };

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

	m_controlButton.setFillColor(sf::Color::White);
	m_controlButton.setSize(m_controlsButtonSize);
	m_controlButton.setPosition(m_controlsButtonPosition);

	m_exitButton.setFillColor(sf::Color::White);
	m_exitButton.setSize(m_exitButtonSize);
	m_exitButton.setPosition(m_exitButtonPosition);


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
		t_window.draw(m_controlButton);
		t_window.draw(m_exitButton);
	}
}

void Menu::checkIfPressed(sf::RenderWindow& window)
{
	// Get mouse position in pixels relative to the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	sf::Vector2f mousePosWindow = window.mapPixelToCoords(pixelPos);

	if (menuActive) {
		sf::FloatRect startButtonZone = m_startButton.getGlobalBounds();
		sf::FloatRect controlButtonZone = m_startButton.getGlobalBounds();
		sf::FloatRect endButtonZone = m_startButton.getGlobalBounds();

		if (startButtonZone.contains(mousePosWindow)) {
			std::cout << "start";
		}
		if (controlButtonZone.contains(mousePosWindow)) {
			std::cout << "controls";
		}
		if (endButtonZone.contains(mousePosWindow)) {
			std::cout << "end";
		}
	}
}