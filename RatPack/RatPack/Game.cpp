#include "Game.h"

#include <iostream>

static float const FPS{ 60.0f };

Game::Game() : m_window(sf::VideoMode({ ScreenSize::s_width, ScreenSize::s_height }, 32 ), "RatPack", sf::Style::Default), m_DELETEexitGame{ false } //when true game will exit
{
	setupTexts(); // load font 
	setupSprites(); // load texture
	setupAudio(); // load sounds

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

		for (int i = 0; i < MAX_RATS; i++)
		{
			m_rats[i].Update(t_deltaTime.asMilliseconds());

			for (int i = 0; i < m_numPlayers; i++)
			{
				if (m_players[i].getSprite().getGlobalBounds().findIntersection(m_rats[i].getSprite().getGlobalBounds()))
				{
					m_numPlayers = m_numPlayers + 1;
				}
			}
			for (int i = 0; i < m_numEnemys; i++)
			{
				if (m_enemys[i].getSprite().getGlobalBounds().findIntersection(m_rats[i].getSprite().getGlobalBounds()))
				{
					//m_rats.erase(i);
					m_numEnemys = m_numEnemys + 1;
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

		for (int i = 0; i < MAX_RATS; i++)
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

void Game::setupTexts()
{
	/*if (!m_jerseyFont.openFromFile("ASSETS\\FONTS\\Jersey20-Regular.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_DELETEwelcomeMessage.setFont(m_jerseyFont);
	m_DELETEwelcomeMessage.setString("SFML Game");
	m_DELETEwelcomeMessage.setPosition(sf::Vector2f{ 205.0f, 240.0f });
	m_DELETEwelcomeMessage.setCharacterSize(96U);
	m_DELETEwelcomeMessage.setOutlineColor(sf::Color::Black);
	m_DELETEwelcomeMessage.setFillColor(sf::Color::Red);
	m_DELETEwelcomeMessage.setOutlineThickness(2.0f);*/
}

void Game::setupSprites()
{
	//if (!m_DELETElogoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	//{
	//	 simple error message if previous call fails
	//	std::cout << "problem loading logo" << std::endl;
	//}
	//
	//m_DELETElogoSprite.setTexture(m_DELETElogoTexture,true);// to reset the dimensions of texture
	//m_DELETElogoSprite.setPosition(sf::Vector2f{ 150.0f, 50.0f });
}

void Game::setupAudio()
{
	//if (!m_DELETEsoundBuffer.loadFromFile("ASSETS\\AUDIO\\beep.wav"))
	//{
	//	std::cout << "Error loading beep sound" << std::endl;
	//}
	//m_DELETEsound.play(); // test sound
}