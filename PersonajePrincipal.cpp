#include "PersonajePrincipal.h"
#include<iostream>

PersonajePrincipal::PersonajePrincipal(int vida, int iniciativa, int def, int atk)
{
	set_vida(vida);
	set_iniciativa(iniciativa);
	set_def(def);
	set_atk(atk);
	setTexturePlayer();
	setPlayer(500.0f, 500.0f);
}

void PersonajePrincipal::setTexturePlayer()
{
	_texturePlayer.loadFromFile("Graphics\\kloster.png");
	_spritePlayer.setTexture(_texturePlayer);
	_spritePlayer.setTextureRect(sf::IntRect(0, 0, 27, 48));
	_spritePlayer.setScale(1.3f, 1.3f);
	if (!_buffer.loadFromFile("musica\\caminata.wav")) {
		std::cout << "NO SE CARGO EL EFECTO" << std::endl;
	}
	_caminata.setBuffer(_buffer);
}

void PersonajePrincipal::setPlayer(float x, float y) {
	_spritePlayer.setPosition(sf::Vector2f(x, y));
	sf::Vector2u tam = sf::Vector2u(_texturePlayer.getSize());
	tam.x /= 6;
	tam.y /= 4;
	_spritePlayer.setOrigin(tam.x / 2, tam.y / 2);
	_estado = estado::quieto;
}

sf::Sprite PersonajePrincipal::getPlayer()
{
	return _spritePlayer;
}

sf::RectangleShape PersonajePrincipal::setCollisionPj()
{
	_collisionPj.setSize({ 50, 25 });
	_collisionPj.setOrigin(sf::Vector2f(50 / 2, 0));
	_collisionPj.setFillColor(sf::Color(300, 300, 300));
	_collisionPj.setPosition(_spritePlayer.getPosition());
	return _collisionPj;
}

void PersonajePrincipal::moverPj(float frame, float x, float y) {
	_caminata.setVolume(100);
	sf::Vector2u tamTextura = sf::Vector2u(_texturePlayer.getSize());
	tamTextura.x /= 6;
	tamTextura.y /= 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_estado = estado::derecha;
		_spritePlayer.move(x + 4.0f, 0.f);
		//derecha
		_spritePlayer.setTextureRect(sf::IntRect(tamTextura.x * ((int)frame % 5), tamTextura.y * 3, tamTextura.x, tamTextura.y));
		if (_caminata.getStatus() != sf::SoundSource::Playing) {
			_caminata.play();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_estado = estado::izquierda;
		_spritePlayer.move(x - 4.0f, 0.f);
		//izquierda
		_spritePlayer.setTextureRect(sf::IntRect(tamTextura.x * ((int)frame % 5), tamTextura.y * 2, tamTextura.x, tamTextura.y));
		if (_caminata.getStatus() != sf::SoundSource::Playing) {
			_caminata.play();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_estado = estado::subiendo;
		_spritePlayer.move(0.f, y - 4.0f);
		//arriba
		_spritePlayer.setTextureRect(sf::IntRect(tamTextura.x * ((int)frame % 6), tamTextura.y * 1, tamTextura.x, tamTextura.y));
		if (_caminata.getStatus() != sf::SoundSource::Playing) {
			_caminata.play();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_estado = estado::bajando;
		_spritePlayer.move(0.f, y + 4.0f);
		//abajo
		_spritePlayer.setTextureRect(sf::IntRect(tamTextura.x * ((int)frame % 6), tamTextura.y * 0, tamTextura.x, tamTextura.y));
		if (_caminata.getStatus() != sf::SoundSource::Playing) {
			_caminata.play();
		}
	}
	else {
		_estado = estado::quieto;
	}
	_collisionPj.setPosition(_spritePlayer.getPosition());
}




sf::Vector2f PersonajePrincipal::getPosition()
{
	sf::Vector2f pos = _spritePlayer.getPosition();
	return pos;
}

estado PersonajePrincipal::getEstado()
{
	return _estado;
}

