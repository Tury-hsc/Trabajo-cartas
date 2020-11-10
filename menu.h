#pragma once
#include"SFML/Graphics.hpp"
#include"gamePlay.h"

class menu {

private:
	
	sf::Font* fuente;
	sf::RectangleShape * rectangulo_seleccion;
	sf::Event * evento;
	sf::RenderWindow* window;
	sf::Texture* textura_fondo;
	sf::Music * _musicaFondo;
	sf::Sprite* sprite_fondo;
	sf::Texture* textura_iconos;
	sf::Texture* textura_tabla;
	sf::Texture* textura_cadena;
	sf::Sprite* sprite_iconos;
	sf::Sprite* cadena1;
	sf::Sprite* cadena2;
	sf::Sprite* tabla;

public:
	void mostrar_menu(Enemigo& e, PersonajePrincipal& p);
	void setFont(sf::String fuente_texto);
	sf::Text setTexto(sf::String texto, unsigned int tamaño_texto, sf::Vector2f ubicacion);
	void definir_rectangulo();
	void eventos(sf::Vector2f posicion, Enemigo& e, PersonajePrincipal& p);
	void setTexture();
	void setSprite();
	void setTexture_iconos();
	void setSprite_iconos();
};