#include <iostream>
#include "Menu.h"
Menu::Menu() {
	menuActive = true;
	//Size Dimensions
	m_startButtonSize = { 255, 120 };
	m_startButtonPosition = { 282, 405 };

	m_controlsButtonSize = { 220, 80 };
	m_controlsButtonPosition = { 134, 586 };

	m_exitButtonSize = { 220, 80 };
	m_exitButtonPosition = { 436, 581 };

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
	m_startButton.setFillColor(sf::Color::Transparent);
	m_startButton.setSize(m_startButtonSize);
	m_startButton.setPosition(m_startButtonPosition);

	m_controlButton.setFillColor(sf::Color::Transparent);
	m_controlButton.setSize(m_controlsButtonSize);
	m_controlButton.setPosition(m_controlsButtonPosition);

	m_exitButton.setFillColor(sf::Color::Transparent);
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
		sf::FloatRect controlButtonZone = m_controlButton.getGlobalBounds();
		sf::FloatRect endButtonZone = m_exitButton.getGlobalBounds();

		if (startButtonZone.contains(mousePosWindow)) {
			menuActive = false;
		}
		if (controlButtonZone.contains(mousePosWindow)) {
			std::cout << "controls";
		}
		if (endButtonZone.contains(mousePosWindow)) {
			window.close();
		}
	}
}

bool Menu::isMenuActive()
{
	return menuActive;
}
