#include "Game.h"

#include <iostream>

static float const FPS{ 60.0f };

Game::Game() : m_window(sf::VideoMode({ ScreenSize::s_width, ScreenSize::s_height }, 32 ), "RatPack", sf::Style::Default), m_DELETEexitGame{ false } //when true game will exit
{
	/*m_rats.resize(MAX_RATS);
	m_players.resize(m_numPlayers);
	m_enemys.resize(m_numEnemys);

	for (auto& rat : m_rats)
	{
		rat.loadAssets();
	}*/

	for (int i = 0; i < MAX_RATS; i++)
	{
		Rat* tempRat = new Rat();
		tempRat->loadAssets();
		m_rats.push_back(tempRat);
	}

	//Globals globals;
	//if (!globals.enemyTexture.loadFromFile("ASSETS\\IMAGES\\enemyRat.png")) 
	//{
	//	std::cout << "Problem loading enemy rat" << std::endl;
	//}
	Enemy tempEnemy;
	//tempEnemy.setSprite(enemyTexture);
	m_enemys.push_back(tempEnemy);

	//if (!globals.playerTexture.loadFromFile("ASSETS\\IMAGES\\playerRat.png"))
	//{
	//	std::cout << "Problem loading player rat" << std::endl;
	//}
	Player tempPlayer;
	//tempPlayer.setSprite(playerTexture);
	m_players.push_back(tempPlayer);

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
		for (int i = 0; i < m_players.size(); i++)
		{
			m_players.at(i).rotationInput(t_event);
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
		for (int i = 0; i < m_players.size(); i++)
		{
			m_players.at(i).move(t_deltaTime.asMilliseconds());
		}

		for (int i = 0; i < m_enemys.size(); i++)
		{
			m_enemys.at(i).enemyUpdate(t_deltaTime.asMilliseconds());
		}

		for (int i = 0; i < m_rats.size(); i++)
		{
			m_rats.at(i)->Update(t_deltaTime.asMilliseconds());

			for (int j = 0; j < m_players.size(); j++)
			{
				if (m_players.at(j).getSprite().getGlobalBounds().findIntersection(m_rats.at(i)->getSprite().getGlobalBounds()))
				{
					//take rat away from rats
					//add rat to players

					Player tempPlayer;
					tempPlayer.setPosition(m_rats.at(i)->getPosition());
					m_players.push_back(tempPlayer);


					//m_rats.erase(m_rats.begin() + i - 1);

					break;
				}
			}
			for (int j = 0; j < m_enemys.size(); j++)
			{
				if (m_enemys.at(j).getSprite().getGlobalBounds().findIntersection(m_rats.at(i)->getSprite().getGlobalBounds()))
				{
					//take rat away from rats
					//add rat to enemys
					//m_rats.erase(i);

					m_rats.at(i)->shouldBeRemoved = true;

					Enemy tempEnemy;
					tempEnemy.setPosition(m_rats.at(i)->getPosition());
					m_enemys.push_back(tempEnemy);

					//m_rats.erase(m_rats.begin() + i - 1);

					break;
				}

				if (m_rats.at(i)->shouldBeRemoved)
				{
					break;
				}
			}
		}

		for (int i = m_rats.size() - 1; i >= 0; --i) {
			if (m_rats[i]->shouldBeRemoved) {
				m_rats.erase(m_rats.begin() + i);
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

		for (int i = 0; i < m_rats.size(); i++)
		{
			//std::cout << i;
			//std::cout << "\n";
			m_window.draw(m_rats.at(i)->getSprite());
		}

		for (int i = 0; i < m_enemys.size(); i++)
		{
			m_window.draw(m_enemys.at(i).getSprite());
		}

		for (int i = 0; i < m_players.size(); i++)
		{
			m_window.draw(m_players.at(i).getSprite());
		}
	}

	m_window.display();
}