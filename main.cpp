#include "main.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

//using namespace std;
//using namespace sf;

int main()
{
	//Create Window
	sf::RenderWindow window(sf::VideoMode(1000, 800), "PiPaPong", sf::Style::Titlebar | sf::Style::Default);
	sf::Event event;

	//Game loop (stops when window closed) 1 time==1 frame 
	while (window.isOpen())
	{
		//Event polling (Ereignisabfrage)
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); 
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		//Update based on polling


		//Render frame 
		window.clear(sf::Color(211, 211, 211)); //Clear old frame or else it becomes a mess 

		//Draw new frame 
		window.display(); //frame is done and can be displayed

	}
	//End of game/application 
	return 0;
}