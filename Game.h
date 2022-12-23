#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <math.h>
/*
	Class acts as Game Engine 
*/
class Game
{
private:
	
	//Window classes 
	sf::RenderWindow* window;
	sf::VideoMode VideoMode; 
	sf::Event event; 

	//Private functions
	void initVariables();
	void initWindow();

public:
	//Public functions

	//Constructor | Destructor
	Game();						//Constructor

	virtual ~Game();			//Destructor

	//Checks if game is running
	const bool running() const; 

	//Functionns
	void pollEvents();
	void update();
	void render();
};