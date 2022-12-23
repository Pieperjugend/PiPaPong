#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp> 
#include <SFML/Window.hpp>


class Player
{
private:
	
	sf::Sprite _Sprite;							//Declare Player Sprite
	sf::Vector2i _Source;						//Declare Source (Sprite Sheet Crop)
	enum _Direction { Down, Left, Right, Up };	//Declare Direction Enumeration

	//ANIMATION DATA
	float _Speed;								//Player Speed
	sf::Clock _AnimClock;						//Player Animation Clock
	sf::Time _AnimTime;							//Player Animation Time

public:

	Player();									//Constructor
	Player(sf::Texture&);						//Overload Constructor
	~Player();									//Destructor

	//Player movement options 
	void moveUp(); 
	void moveDown(); 
	void moveLeft(); 
	void moveRight(); 
	void setSpeed(float,sf::Time);

	//Acseccor function
	sf::Sprite getSprite() const;
};

#endif // PLAYER_H
