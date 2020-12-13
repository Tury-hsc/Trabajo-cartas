#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class npc
{
private:
	sf::String _nombre;
	sf::Texture _textureNpc;
	sf::Sprite _spriteNpc;
	sf::Font _fuente;
	sf::Text _text;

public:
	npc(sf::String nombre, sf::String texto, sf::String fuente);
	sf::Sprite getNpc() { return _spriteNpc; }
	void setNpc(float x, float y);
	void setTextureNpc(std::string x);
	void set_nombre(sf::String n);
	void setText(std::string x);
	void setFont(sf::String fuente);

};

