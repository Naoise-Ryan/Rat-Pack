#include "Game.h"

#include <iostream>

static float const FPS{ 60.0f };

Game::Game() : m_window(sf::VideoMode({ ScreenSize::s_width, ScreenSize::s_height }, 32 ), "RatPack", sf::Style::Default), m_DELETEexitGame{ false } //when true game will exit
{
	for (int i = 0; i < MAX_RATS; i++)
	{
		m_rats[i].loadAssets();
	}

	m_menu.initialise();

	if (!m_gameBgTexture.loadFromFile("ASSETS\\IMAGES\\game_bg_image.png")) {
		std::cout << "Problem loading bg sprite" << std::endl;
	}
	m_gameBgSprite.setTexture(m_gameBgTexture, true);// to reset the dimensions of texture
	m_gameBgSprite.setPosition(m_gameBgPosition);
}

Game::~Game()
{
}

void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(timePerFrame.asMilliseconds()); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(timePerFrame.asMilliseconds()); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents(double dt)
{
	while (const std::optional newEvent = m_window.pollEvent())
	{
		if ( newEvent->is<sf::Event::Closed>()) // close window message 
		{
			m_DELETEexitGame = true;
		}
		if (!m_menu.isMenuActive()) {
			if (newEvent->is<sf::Event::KeyPressed>()) //user pressed a key
			{
				processKeys(newEvent, dt);
			}
		}
		if (newEvent->is<sf::Event::MouseButtonReleased>()) {
			m_menu.checkIfPressed(m_window);
		}
	}
}

void Game::processKeys(const std::optional<sf::Event> t_event, double dt)
{
	const sf::Event::KeyPressed *newKeypress = t_event->getIf<sf::Event::KeyPressed>();
	if (sf::Keyboard::Key::Escape == newKeypress->code)
	{
		m_DELETEexitGame = true; 
	}
	if (!m_menu.isMenuActive()) {
		for (int i = 0; i < m_numPlayers; i++)
		{
			m_players[i].rotationInput(t_event);
		}
	}
}

void Game::checkKeyboardState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		m_DELETEexitGame = true; 
	}
}

void Game::update(sf::Time t_deltaTime)
{
	checkKeyboardState();
	if (m_DELETEexitGame)
	{
		m_window.close();
	}

	if (!m_menu.isMenuActive()) 
	{
		for (int i = 0; i < m_numPlayers; i++)
		{
			m_players[i].move(t_deltaTime.asMilliseconds());
		}

		for (int i = 0; i < m_numEnemys; i++)
		{
			m_enemys[i].enemyUpdate(t_deltaTime.asMilliseconds());
		}

		for (int i = 0; i < m_numRats; i++)
		{
			m_rats[i].Update(t_deltaTime.asMilliseconds());

			for (int i = 0; i < m_numPlayers; i++)
			{
				if (m_players[i].getSprite().getGlobalBounds().findIntersection(m_rats[i].getSprite().getGlobalBounds()))
				{
					//take rat away from rats
					//add rat to players
					m_numPlayers = m_numPlayers + 1;
					break;
				}
			}
			for (int i = 0; i < m_numEnemys; i++)
			{
				if (m_enemys[i].getSprite().getGlobalBounds().findIntersection(m_rats[i].getSprite().getGlobalBounds()))
				{
					//take rat away from rats
					//add rat to enemys
					//m_rats.erase(i);
					m_numEnemys = m_numEnemys + 1;
					break;
				}
			}
		}
	}
}

void Game::render()
{
	m_window.clear(ULTRAMARINE);

	m_menu.render(m_window);

	if (!m_menu.isMenuActive()) 
	{
		m_window.draw(m_gameBgSprite);

		for (int i = 0; i < m_numRats; i++)
		{
			m_window.draw(m_rats[i].getSprite());
		}

		for (int i = 0; i < m_numEnemys; i++)
		{
			m_window.draw(m_enemys[i].getSprite());
		}

		for (int i = 0; i < m_numPlayers; i++)
		{
			m_window.draw(m_players[i].getSprite());
		}
	}

	m_window.display();
}