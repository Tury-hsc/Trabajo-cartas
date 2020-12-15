#pragma once
#include "Enemigo.h"
#include "PersonajePrincipal.h"
#include "mapa.h"
#include "Mazo.h"
#include "dungeon.h"
#include"npc.h"

class gamePlay
{
private:	
	float frame , x, y;
	sf::Vector2f pos;// = kloster.getPosition();	
	//PersonajePrincipal p;
	mapa mapaPrincipal;
	mapa ciudad;
	//Enemigo e;
	
public:
	gamePlay();
	void collisionObjetos(PersonajePrincipal& p, Enemigo& e, sf::RenderWindow* window);
	void collisionMapa(PersonajePrincipal& p);
	void mostrarVentana(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p);
	void collisionDg(dungeon d, PersonajePrincipal& p, sf::RenderWindow* window, Enemigo& e);
	void collisionRio(PersonajePrincipal& p);
	void collisionNpc(PersonajePrincipal& p, npc& np, sf::RenderWindow * window);
};

