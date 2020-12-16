#include "npc.h"

npc::npc(sf::String nombre, char* texto, sf::String fuente)
{
	setFont(fuente);
	set_nombre(nombre);
	setText(texto);
	
}

void npc::setNpc(float x, float y)
{
	sf::Vector2u tamTextura = sf::Vector2u(_textureNpc.getSize());
	tamTextura.x /= 6;
	tamTextura.y /= 4;
	_spriteNpc.setTextureRect(sf::IntRect(tamTextura.x * 0, tamTextura.y * 0, tamTextura.x, tamTextura.y));
	_spriteNpc.setPosition(x, y);
}

void npc::setTextureNpc()
{
	_textureNpc.loadFromFile("Graphics\\kloster.png");
	_spriteNpc.setTexture(_textureNpc);
	_spriteNpc.setTextureRect(sf::IntRect(0, 0, 27, 48));
	_spriteNpc.setScale(1.3f, 1.3f);
}

void npc::set_nombre(sf::String n)
{
	_nombre = n;
}

void npc::setText(std::string x)
{	
	_text.setFont(_fuente);
	_text.setString(x);
	_text.setCharacterSize(21.5f);
	_text.setPosition(35, 630);
	_text.setOutlineColor(sf::Color::Black);
	_text.setOutlineThickness(2);

	_textNombre.setFont(_fuente);
	_textNombre.setString(_nombre);
	_textNombre.setCharacterSize(21.5f);
	_textNombre.setPosition(35, 590);
	_textNombre.setOutlineColor(sf::Color::Black);
	_textNombre.setOutlineThickness(2);
}

void npc::setFont(sf::String fuente)
{
	_fuente.loadFromFile(fuente);
}

sf::RectangleShape npc::setCollisionNpc(float x, float y)
{
	sf::RectangleShape _collisionNpc(sf::Vector2f(50, 50));
	_collisionNpc.setOrigin(sf::Vector2f(50 / 2, 50 / 2));
	_collisionNpc.setFillColor(sf::Color::Black);
	_collisionNpc.setPosition(x, y);
	return _collisionNpc;
}
