#include "Player.h"

Player::Player()			//Constructor 
{

}

Player::Player(sf::Texture& Temp_Texture)	//Overload Constructor
{
	//Player Sprite
	_Sprite.setTexture(Temp_Texture);												//Set Sprite Texture 
	_Sprite.setPosition(650 - 32,300 -32);											//Set Sprite Position (Half of X - 32, Half of y - 32(Centre))
	_Sprite.setScale(1.5f, 1.5f);													//Sprite scale
	sf::Vector2i _Source(1, Down);													//Default Sprite Sheet Crop
	_Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32));	//Crop Sprite

	//Sheet (Default Crop)

	//Player | Animation Speed
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

	if (_AnimClock.getElapsedTime() > _AnimTime)
	{
		_Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32)); //Crop Sprite

		//Animation 
			_Source.x++;
		if (_Source.x * 32 >= _Sprite.getTexture()->getSize().x)
		{
			_Source.x = 0;
		}
		_AnimClock.restart();
	}
}

void Player::moveDown()
{
	_Source.y = Down;				//Move Direction enum
	_Sprite.move(0, -_Speed);		//Move Player Sprite 

	if (_AnimClock.getElapsedTime() > _AnimTime)
	{
		_Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32)); //Crop Sprite

		//Animation 
		_Source.x++;
		if (_Source.x * 32 >= _Sprite.getTexture()->getSize().x)
		{
			_Source.x = 0;
		}
		_AnimClock.restart();
	}

}

void Player::moveLeft()
{
	_Source.y = Left;				//Move Direction enum
	_Sprite.move(0, -_Speed);		//Move Player Sprite 

	if (_AnimClock.getElapsedTime() > _AnimTime)
	{
		_Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32)); //Crop Sprite

		//Animation 
		_Source.x++;
		if (_Source.x * 32 >= _Sprite.getTexture()->getSize().x)
		{
			_Source.x = 0;
		}
		_AnimClock.restart();
	}
}

void Player::moveRight() 
{
	_Source.y = Left;				//Move Direction enum
	_Sprite.move(0, -_Speed);		//Move Player Sprite 

	if (_AnimClock.getElapsedTime() > _AnimTime)
	{
		_Sprite.setTextureRect(sf::IntRect(_Source.x * 32, _Source.y * 32, 32, 32)); //Crop Sprite

		//Animation 
		_Source.x++;
		if (_Source.x * 32 >= _Sprite.getTexture()->getSize().x)
		{
			_Source.x = 0;
		}
		_AnimClock.restart();
	}
} 

void Player::setSpeed(float TEMP_Speed, sf::Time TEMP__AnimTime)	//Sprint Speed
{
	_Speed = TEMP_Speed;
	_AnimTime = TEMP__AnimTime;
}
