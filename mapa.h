#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
class mapa
{
private:
	sf::Texture _textureMap;
	sf::Sprite _spriteMap;
public:
	sf::Sprite getMap();
	void setMap(int x, int y);
	void setTextureMap(std::string x);



};

