#include <iostream>
#include "Menu.h"
Menu::Menu() {
	menuActive = true;
	controlMenuActive = false;
	Music1();
	//Size Dimensions
	m_startButtonSize = { 255, 120 };
	m_startButtonPosition = { 282, 405 };

	m_controlsButtonSize = { 220, 80 };
	m_controlsButtonPosition = { 134, 586 };

	m_exitButtonSize = { 220, 80 };
	m_exitButtonPosition = { 436, 581 };

	m_goBackButtonSize = { 275, 115 };
	m_goBackButtonPosition = { 18, 18 };

	m_menuBgPosition = { 0.0f, 0.0f };
}

void Menu::openMenu()
{
	menuActive = true;
	controlMenuActive = false;
}
void Menu::closeMenu()
{
	menuActive = false;
	controlMenuActive = false;
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

	m_goBackButton.setFillColor(sf::Color::Transparent);
	m_goBackButton.setSize(m_goBackButtonSize);
	m_goBackButton.setPosition(m_goBackButtonPosition);


	if (!m_menuBgTexture.loadFromFile("ASSETS\\IMAGES\\menu_image.png")) {
		std::cout << "Problem loading bg sprite" << std::endl;
	}
	m_menuBgSprite.setTexture(m_menuBgTexture, true);// to reset the dimensions of texture
	m_menuBgSprite.setPosition(m_menuBgPosition);

	if (!m_controlBgTexture.loadFromFile("ASSETS\\IMAGES\\controls_bg_image.png")) {
		std::cout << "Problem loading bg sprite" << std::endl;
	}
	m_controlBgSprite.setTexture(m_controlBgTexture, true);// to reset the dimensions of texture
	m_controlBgSprite.setPosition(m_controlBgPosition);
}

void Menu::render(sf::RenderWindow& t_window)
{
	if (menuActive) {
		if (!controlMenuActive) {
			t_window.draw(m_menuBgSprite);
			t_window.draw(m_startButton);
			t_window.draw(m_controlButton);
			t_window.draw(m_exitButton);
		}
		else {
			t_window.draw(m_controlBgSprite);
			t_window.draw(m_goBackButton);
		}
	}
}

void Menu::checkIfPressed(sf::RenderWindow& window)
{
	// Get mouse position in pixels relative to the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	sf::Vector2f mousePosWindow = window.mapPixelToCoords(pixelPos);

	if (menuActive) {
		if (!controlMenuActive) {
			sf::FloatRect startButtonZone = m_startButton.getGlobalBounds();
			sf::FloatRect controlButtonZone = m_controlButton.getGlobalBounds();
			sf::FloatRect endButtonZone = m_exitButton.getGlobalBounds();

			if (startButtonZone.contains(mousePosWindow)) {
				menuActive = false;
				Music2();
			}
			if (controlButtonZone.contains(mousePosWindow)) {
				controlMenuActive = true;
			}
			if (endButtonZone.contains(mousePosWindow)) {
				window.close();
			}
		}
		else {
			sf::FloatRect goBackButtonZone = m_goBackButton.getGlobalBounds();
			if (goBackButtonZone.contains(mousePosWindow)) {
				menuActive = true;
				controlMenuActive = false;
			}
		}
	}
}

bool Menu::isMenuActive()
{
	return menuActive;
}

void Menu::Music1()
{
	if (!m_music1.openFromFile("ASSETS\\AUDIO\\title.wav"))
	{
		std::cout << "Error loading menu theme" << std::endl;
	}
	else {
		m_music1.play();
		m_music2.stop();
	}
}

void Menu::Music2()
{
	if (!m_music2.openFromFile("ASSETS\\AUDIO\\game.wav"))
	{
		std::cout << "Error loading menu theme" << std::endl;
	}
	else {
		m_music2.play();
		m_music1.stop();
	}
}