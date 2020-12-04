#include "aniomaciones.h"

animaciones::animaciones()
{
	setTexture();
}

void animaciones::setTexture()
{
	_textureDanio.loadFromFile("Graphics\\carta_danio.png");
	_spriteDanio.setTexture(_textureDanio);
}

void animaciones::setAnimacion(float x, float y)
{
	_spriteDanio.setPosition(sf::Vector2f(x, y));
	sf::Vector2u tam = sf::Vector2u(_textureDanio.getSize());
	tam.x /= 7;
	tam.y /= 4;
	_spriteDanio.setOrigin(tam.x / 2, tam.y / 2);
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {			
			_spriteDanio.setTextureRect(sf::IntRect(tam.x * j, tam.y * i, tam.x, tam.y));			
		}
	}
}
