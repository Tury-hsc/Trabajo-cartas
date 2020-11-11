#include "Enemigo.h"
#include <time.h>
#include <iostream>
Enemigo::Enemigo(int vida, int iniciativa, int def, int atk)
{
	set_vida(vida);
	set_iniciativa(iniciativa);
	set_def(def);
	set_atk(atk);
	setTextureDragon();
	setDragon();
	setScaleDragon();
}
int Enemigo::danio_a_personaje()
{	
	int x;
	srand(time(NULL));
	x=20/*this->get_atk()*/;
	x=rand()%x+1;
	return x*-1;
}
void Enemigo::setTextureDragon()
{
	_textureDragon.loadFromFile("Graphics\\dragon.png");
	_spriteDragon.setTexture(_textureDragon);
	_spriteDragon.setTextureRect(sf::IntRect(0, 0, 57, 99));
}

void Enemigo::setScaleDragon()
{
	_spriteDragon.setScale(1.6f, 1.6f);
}

sf::RectangleShape Enemigo::setCollisionDragon()
{
	sf::RectangleShape _collisionDragon(sf::Vector2f(170, 50));
	_collisionDragon.setOrigin(sf::Vector2f(170 / 2, 50 / 2));
	_collisionDragon.setFillColor(sf::Color::Transparent);
	_collisionDragon.setPosition(280.0f, 380.0f);
	return _collisionDragon;
}


sf::Sprite Enemigo::getDragon()
{
	return _spriteDragon;
}

void Enemigo::setDragon()
{
	sf::Vector2u tamTextura = sf::Vector2u(_textureDragon.getSize());
	tamTextura.x /= 3;
	tamTextura.y /= 4;
	_spriteDragon.setTextureRect(sf::IntRect(tamTextura.x * 0, tamTextura.y * 0, tamTextura.x, tamTextura.y));
	_spriteDragon.setPosition(sf::Vector2f(20.0f, 20.0f));
}
