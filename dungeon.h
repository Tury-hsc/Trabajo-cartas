#pragma once
#include <iostream>
#include "Estadisticas.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "mapa.h"
class dungeon
{
private:
	sf::Texture _textureDg;
	sf::Sprite _spriteDg;
public:
	dungeon();
	sf::Sprite getDungeon();
	void setDungeon();
	void setTextureDungeon();
	void setScaleDungeon();
	sf::RectangleShape setCollisionDg();
};

