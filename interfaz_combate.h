#pragma once
#include"SFML/Graphics.hpp"
#include"gamePlay.h"
#include"turno.h"

class combate {

private:
	sf::Texture* textura_vida;
	sf::Texture* textura_opcion;
	sf::Texture* textura_combate;
	sf::Texture* textura_personaje;
	sf::Texture* textura_enemigo;
	sf::Texture* textura_fondo;
	sf::Texture* textura_boton;
	sf::Sprite* sprite_fondo;
	sf::Sprite* sprite_vida;
	sf::Sprite* sprite_opcion;
	sf::Sprite* sprite_vida_enemigo;
	sf::Sprite* sprite_combate;
	sf::Sprite* sprite_personaje;
	sf::Sprite* sprite_enemigo;
	sf::Sprite* sprite_boton;
	sf::Font* fuente_combate;
	int vida_personaje;
	int vida_enemigo;
	bool huir = false;
	bool atacar = false;
	turno t;
	
public:

	void setTexture_combate(Enemigo& e/*, PersonajePrincipal& k*/);
	void setSprite_combate();
	void setSprite_pj(Enemigo e);
	void iniciar_pelea(sf::RenderWindow* window,Enemigo& e, PersonajePrincipal& p);
	void setFont();
	sf::Text setTexto(sf::String texto, unsigned int tamaño_texto, sf::Vector2f ubicacion, float grueso);
	void procesar_eventos(sf::RenderWindow* window, sf::Vector2f posicion,turno t, Enemigo& e, PersonajePrincipal& p,Mazo &m);
	void definir_vida();

};