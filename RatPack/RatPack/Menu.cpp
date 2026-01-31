#include <iostream>
#include "Menu.h"
Menu::Menu() {
	menuActive = false;
	//Size Dimensions
	m_startButtonSize = { 100, 100 };
	m_startButtonPosition = { 100, 100 };
}

void Menu::openMenu()
{
	menuActive = true;
}
void Menu::initialise()
{
	//Start Button
	m_startButton.setFillColor(sf::Color::White);
	m_startButton.setSize(m_startButtonSize);
	m_startButton.setPosition(m_startButtonPosition);
}

void Menu::render(sf::RenderWindow& t_window)
{
	if (menuActive) {
		t_window.draw(m_startButton);
	}
}

void Menu::setupFontAndText()
{
}

void Menu::checkIfPressed(sf::Event t_newEvent, sf::RenderWindow& window)
{
}