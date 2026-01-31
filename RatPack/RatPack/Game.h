#ifndef GAME_HPP
#define GAME_HPP
#pragma warning( push )
#pragma warning( disable : 4275 )
// ignore this warning
// C:\SFML - 3.0.0\include\SFML\System\Exception.hpp(41, 47) : 
// warning C4275 : non dll - interface class 'std::runtime_error' used as base for dll - interface class 'sf::Exception'

#include "ScreenSize.h"
#include "Menu.h"

#include "Player.h"
#include "Enemy.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

const sf::Color ULTRAMARINE{ 5, 55,242,255 }; // const colour

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void processEvents(double dt);
	void processKeys(const std::optional<sf::Event> t_event, double dt);
	void checkKeyboardState();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupTexts();
	void setupSprites();
	void setupAudio();

	
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_jerseyFont;// font used by message

	const static int MAX_RATS = 20;
	int m_numRats = MAX_RATS;
	std::vector<Rat> m_rats;
	int m_numPlayers = 1;
	std::vector<Player> m_players;
	int m_numEnemys = 1;
	std::vector<Enemy> m_enemys;
	
	bool m_DELETEexitGame; // control exiting game

	Menu m_menu;

	//Menu Sprite
	sf::Texture m_gameBgTexture;
	sf::Sprite m_gameBgSprite{ m_gameBgTexture };
	sf::Vector2f m_gameBgPosition;
};

#pragma warning( pop ) 
#endif // !GAME_HPP