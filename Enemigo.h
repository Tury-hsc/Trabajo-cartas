#pragma once
#include <iostream>
#include "Estadisticas.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "mapa.h"
class Enemigo : public Estadisticas
{
	
private:
	sf::Texture _textureDragon;
	sf::Sprite _spriteDragon;
	char _nombre[20];
	bool _pierdeturno;
public:
	
	Enemigo(int vida, int iniciativa, int def, int atk);
	int danio_a_personaje();
	sf::Sprite getDragon();
	void setDragon();
	void setTextureDragon();
	void setScaleDragon();

	sf::RectangleShape setCollisionDragon();

	
};

