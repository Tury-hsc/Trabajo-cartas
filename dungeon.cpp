#include "dungeon.h"

dungeon::dungeon()
{
	setTextureDungeon();
	setDungeon();
}

sf::Sprite dungeon::getDungeon()
{
	return _spriteDg;
}

void dungeon::setDungeon()
{
	_spriteDg.setPosition(sf::Vector2f(100.0f, 100.0f));
}

void dungeon::setTextureDungeon()
{
	_textureDg.loadFromFile("Graphics\\dungeon_fuego.png");
	_spriteDg.setTexture(_textureDg);
	_spriteDg.setTextureRect(sf::IntRect(0, 0, 158, 154));
}

sf::RectangleShape dungeon::setCollisionDg()
{
	sf::RectangleShape _collisionDg(sf::Vector2f(50, 25));
	_collisionDg.setOrigin(sf::Vector2f(50 / 2, 25 / 2));
	_collisionDg.setFillColor(sf::Color::Transparent);
	_collisionDg.setPosition(170.0f, 220.0f);
	return _collisionDg;
}


