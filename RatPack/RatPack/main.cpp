#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include "Game.h"
#include "Rat.h"

sf::Texture Rat::m_Texture;



int main()
{
	srand(time(nullptr));

	if (!Rat::m_Texture.loadFromFile("ASSETS\\IMAGES\\rat.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading rat" << std::endl;
	}

	Game game;
	game.run();

	return EXIT_SUCCESS; // 0
}