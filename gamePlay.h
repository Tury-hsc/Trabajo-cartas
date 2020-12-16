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
	bool musica1 = true;
	sf::Vector2f pos;// = kloster.getPosition();	
	//PersonajePrincipal p;
	mapa mapaPrincipal;
	mapa ciudad;
	sf::Texture* textura_dialogo;
	sf::Sprite* dialogo;
	//Enemigo e;
	
public:
	gamePlay();
	void setCuadroDialogo();
	void collisionObjetos(PersonajePrincipal& p, Enemigo& e, sf::RenderWindow* window);
	void collisionMapa(PersonajePrincipal& p);
	void mostrarVentana(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p, float posx, float posy);
	void collisionDg(dungeon d, PersonajePrincipal& p, sf::RenderWindow* window, Enemigo& e);
	void collisionRio(PersonajePrincipal& p);
	void collisionNpc(PersonajePrincipal& p, npc& np, sf::RenderWindow * window);
	void collisionBosque(PersonajePrincipal& p, sf::RectangleShape paso, sf::RenderWindow* window, Enemigo& e);
	void mapa2(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p, float posx, float posy);
	void collisionCiudad(PersonajePrincipal& p, sf::RectangleShape paso, sf::RenderWindow* window, Enemigo& e);
	void collisionCerca(PersonajePrincipal& p);
	void collisionFuente(PersonajePrincipal& p);
	void collisionPlantas(PersonajePrincipal& p);
	void collisionSillas(PersonajePrincipal& p);
	void collisionParteDerecha(PersonajePrincipal& p);
	void collisionParteDerechaAbajo(PersonajePrincipal& p);
};

