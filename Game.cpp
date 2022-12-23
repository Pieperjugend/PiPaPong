#include <iostream>
#include "Game.h"

//Private functions 
void Game::initVariables()
{
	/* 
		Window Nullptr
	*/
	this->window = nullptr;
}

void Game::initWindow() 
{
	/*
		Creates window
			-style
			-width
			-height
			-title
		Set Frameratelimit to 60fps
		disable vertical sync or enable with true i dont know what is better jet
	*/
	this->VideoMode.height = 1200;	// Y 
	this->VideoMode.width = 700;	// X				X	 Y
	this->window = new sf::RenderWindow(sf::VideoMode(1200, 700), "PiPaPong", sf::Style::Titlebar | sf::Style::Default);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

//Constructors | Destructors
Game::Game() 
{
	/*
		(Constructor)
		initVariable initializes window nullptr
		initWindow initializes Window
			-width
			-height
			-RenderWindow
		Opens window witch line 38-47 are checking 
	*/
	this->initVariables(); 
	this->initWindow();
}

Game::~Game()
{
	/*
	Closes window (Destructor)
	*/
	delete this->window; 
}

//Zugriff 
const bool Game::running() const 
{
	/* 
		Checks if window is still open
			-Window is open=true
			-window is closed=false
	*/
	return this->window->isOpen();
}

//functions

//updating the szene
void Game::update()
{
	/*
		pollEvent (Ereignisabfrage) 
			-Escape->Colse window & stop programm
			-close window->stop programm
	*/
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

//projecting current state 
void Game::render()
{
	/*
		Renders Window Frames 
			-Clears old Frame
			-Changes background color to grey
			-draws new objects
	*/
	this->window->clear(sf::Color(75, 75, 75, 255));
	//Draw game objects
	this->window->display(); 
}

void Game::pollEvents()
{
	/*
		Waits for an Event
		example: Escape = Close window
	*/
	this->pollEvents();
}