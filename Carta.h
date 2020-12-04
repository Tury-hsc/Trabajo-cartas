#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Carta
{	
private:
	char _nombre[20];
	int _valor;
	bool _afectaPersonaje,_stun;
	sf::Texture _textureDanio;
	sf::Sprite _spriteDanio;
	
public:
	void set_nombre(char* c);
	void set_valor(int x);
	void set_afectaPersonaje(bool x);
	void set_stun(bool x);
	bool get_afectaPersonaje();
	int  get_valor();
	char * get_nombre();
	void crear_carta();
	bool get_stun();	
	
};

