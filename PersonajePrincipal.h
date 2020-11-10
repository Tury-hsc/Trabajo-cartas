#pragma once
#include "Estadisticas.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "mapa.h"

enum estado {
	quieto,
	subiendo,
	bajando,
	derecha,
	izquierda,
	pelea,
};

class PersonajePrincipal : public Estadisticas{
	private: 

		sf::Texture _texturePlayer;
		sf::Sprite _spritePlayer;
		sf::SoundBuffer _buffer;
		sf::Sound _caminata;
		sf::RectangleShape _collisionPj;
		estado _estado;
	
	public:
		sf::Sprite getPlayer();
		void setPlayer(float x, float y);
		void setTexturePlayer();
		void moverPj(float frame, float x, float y);
		sf::RectangleShape setCollisionPj();
		sf::Vector2f getPosition();
		estado getEstado();

	PersonajePrincipal(int vida, int iniciativa, int def, int atk);
				
};

