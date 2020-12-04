#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class animaciones
{
private:	
	sf::Texture _textureDanio;
	sf::Sprite _spriteDanio;
	sf::Texture _textureStun;
	sf::Sprite _spriteStun;
	sf::Texture _textureCurar;
	sf::Sprite _spriteCurar;
public:
	animaciones();
	void setTexture();
	void setAnimacion(float x, float y);
};

