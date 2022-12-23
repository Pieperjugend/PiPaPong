#include "Player.h"
#include "Game.h"

Player::Player()			//Constructor 
{

}

Player::Player(sf::Texture& Temp_Texture)	//Overload Constructor
{
	//Player Sprite
	_Sprite.setTexture(Temp_Texture);												//Set Sprite Texture 
	_Sprite.setPosition(650 - 32,300 -32);											//Set Sprite Position (Half of X - 32, Half of y -32(Centre))
	_Sprite.setScale(1.5f, 1.5f);													//Sprite scale
	sf::Vector2i _Source(1, Down);													//Default Sprite Sheet Crop
	_Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32));	//Crop Sprite

	//Sheet (Default Crop)

	//Player|Animation Speed
	_AnimTime = sf::milliseconds(80);	//Animation Speed
	_Speed = 0.20;						//Player Speed
}

Player::~Player()			//Destructor	
{

}

//Accessor Functions
sf::Sprite Player::getSprite() const		//Player Sprite 
{
	return _Sprite; 
}

 //Player movement
void Player::moveUp()
{
	_Source.y = Up;					//Move Direction enum
	_Sprite.move(0, -_Speed);		//Move Player Sprite 


}