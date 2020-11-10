#include "mapa.h"

void mapa::setTextureMap()
{
	_textureMap.loadFromFile("Graphics\\mapa.png");
	_spriteMap.setTexture(_textureMap);
}

void mapa::setMap()
{
	//_spriteMap.setPosition(sf::Vector2f(300.0f, 300.0f));
	sf::Vector2u tamMapa = sf::Vector2u(_textureMap.getSize());
	tamMapa.x /= 2;
	tamMapa.y /= 2;
	_spriteMap.setOrigin(sf::Vector2f(tamMapa));
	_spriteMap.setPosition(550, 300);
}

sf::Sprite mapa::getMap()
{
	return _spriteMap;
}
