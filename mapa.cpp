#include <iostream>
#include "mapa.h"

void mapa::setTextureMap(std::string x)
{
	_textureMap.loadFromFile(x);
	_spriteMap.setTexture(_textureMap);
}

void mapa::setMap(int x, int y)
{
	//_spriteMap.setPosition(sf::Vector2f(300.0f, 300.0f));
	sf::Vector2u tamMapa = sf::Vector2u(_textureMap.getSize());
	tamMapa.x /= 2;
	tamMapa.y /= 2;
	_spriteMap.setOrigin(sf::Vector2f(tamMapa));
	_spriteMap.setPosition(x, y);
}

sf::Sprite mapa::getMap()
{
	return _spriteMap;
}
