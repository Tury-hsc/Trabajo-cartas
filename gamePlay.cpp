#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "Enemigo.h"
#include "mapa.h"
#include "PersonajePrincipal.h"
#include "gamePlay.h"
#include "interfaz_combate.h"
#include "npc.h"
#include "Texto.h"

//p(40,20,20,20) , e (30,10,20,20)
gamePlay::gamePlay() {
	frame = 0;
	x = 0;
	y = 0;
}

void gamePlay::collisionObjetos(PersonajePrincipal& p, Enemigo& e, sf::RenderWindow* window)
{
	if (p.setCollisionPj().getGlobalBounds().intersects(e.setCollisionDragon().getGlobalBounds())) {
		combate pelea;
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= e.setCollisionDragon().getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= e.setCollisionDragon().getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= e.setCollisionDragon().getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= e.setCollisionDragon().getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 0:
			break;
		}
	}
}

void gamePlay::collisionMapa(PersonajePrincipal& p)
{
	if (p.getPosition().x >= 1010.f) {
		p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
	}
	if (p.getPosition().y >= 690.f) {
		p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
	}
	if (p.getPosition().x <= 20) {
		p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
	}
	if (p.getPosition().y <= 20) {
		p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
	}
	
	
}

void gamePlay::collisionNpc(PersonajePrincipal& p, npc& np, sf::RenderWindow* window) {

	if (p.setCollisionPj().getPosition().y >= 515 && p.setCollisionPj().getPosition().y <= 565) {//BAJANDO
		if (p.setCollisionPj().getPosition().x >= 655 && p.setCollisionPj().getPosition().x <= 705)
			window->draw(np.getText());
	}
}

void gamePlay::mostrarVentana(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p, float posx, float posy)
{
	sf::Music _musicaFondo;
	
	
	if (!_musicaFondo.openFromFile("musica\\pelea3.wav")) {
		std::cout << "No se pudo cargar el sonido" << std::endl;
	}

	dungeon d;	
	Texto ff;

	char a[300];
	strcpy(a, ff.obtenerTexto(0));

	npc np("Brian Lara", a, "Enchanted_Land.otf");

	np.setTextureNpc();
	np.setNpc(674, 460);

	sf::RectangleShape paso;
	paso.setSize({ 157,20 });
	paso.setFillColor(sf::Color::Black);
	paso.setPosition(400, 25);

	ciudad.setTextureMap("Graphics\\ciudad.png");
	ciudad.setMap(500, 250);

	mapaPrincipal.setTextureMap("Graphics\\mapa.png");
	mapaPrincipal.setMap(550, 300);

	if (musica1 == true) {
		_musicaFondo.play();
		_musicaFondo.setVolume(20);
		musica1 = false;
	}

	p.setPlayer(posx, posy);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			
		}		
		collisionMapa(p);	
		collisionBosque(p, paso, window, e);
		//collisionRio(p);
		//collisionDg(d,p,window,e);
		p.moverPj(frame, x, y);
		//std::cout << a << endl;
		window->draw(ciudad.getMap());
		window->draw(paso);
		//window->draw(d.getDungeon());
		//window->draw(d.setCollisionDg());		
		window->draw(p.setCollisionPj());
		window->draw(p.getPlayer());
		window->draw(np.getNpc());
		window->draw(np.setCollisionNpc(680, 540));
		collisionNpc(p, np, window);
		window->display();
		frame += .2f;
	}
	_musicaFondo.stop();
}

void gamePlay::mapa2(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p, float posx, float posy)
{

	dungeon d;
	
	sf::RectangleShape paso;
	paso.setSize({ 157,20 });
	paso.setFillColor(sf::Color::Black);
	paso.setPosition(400, 700);

	mapaPrincipal.setTextureMap("Graphics\\mapa.png");
	mapaPrincipal.setMap(500, 250);

	mapaPrincipal.setTextureMap("Graphics\\mapa.png");
	mapaPrincipal.setMap(550, 300);

	p.setPlayer(posx, posy);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed) {

			}
		}
		collisionMapa(p);
		collisionCiudad(p, paso, window, e);
		collisionRio(p);
		collisionDg(d,p,window,e);
		p.moverPj(frame, x, y);
		//std::cout << a << endl;
		window->draw(mapaPrincipal.getMap());
		window->draw(paso);
		window->draw(d.getDungeon());
		window->draw(d.setCollisionDg());		
		window->draw(p.setCollisionPj());
		window->draw(p.getPlayer());
		//window->draw(np.getNpc());
		//window->draw(np.setCollisionNpc(20, 400));
		//collisionNpc(p, np, window);
		window->display();
		frame += .2f;
	}
	
}

void gamePlay::collisionDg(dungeon d, PersonajePrincipal& p, sf::RenderWindow* window, Enemigo& e)
{
	if (p.setCollisionPj().getGlobalBounds().intersects(d.setCollisionDg().getGlobalBounds())) {
		combate pelea;
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= d.setCollisionDg().getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= d.setCollisionDg().getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= d.setCollisionDg().getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= d.setCollisionDg().getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
				pelea.iniciar_pelea(window, e, p);
			}
			break;
		case 0:
			break;
		}
	}
}

void gamePlay::collisionRio(PersonajePrincipal& p) {
	sf::RectangleShape rio;
	rio.setSize({ 360,197 });
	rio.setFillColor(sf::Color::Black);
	rio.setPosition(590, 210);

	sf::RectangleShape rio_arriba;
	rio_arriba.setSize({ 205,50 });
	rio_arriba.setFillColor(sf::Color::Black);
	rio_arriba.setPosition(590, 161);

	if (p.setCollisionPj().getGlobalBounds().intersects(rio.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= rio.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= rio.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= rio.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= rio.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(rio_arriba.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= rio_arriba.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= rio_arriba.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= rio_arriba.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= rio_arriba.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
}

void gamePlay::collisionBosque(PersonajePrincipal& p, sf::RectangleShape paso, sf::RenderWindow* window, Enemigo& e) {

	if (p.setCollisionPj().getGlobalBounds().intersects(paso.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 1:
			if (p.setCollisionPj().getPosition().y >= paso.getPosition().y) {//SUBIENDO
				window->clear();
				mapa2(window, e, p, 450, 640);
			}
			break;
		case 0:
			break;
		}
	}
}

void gamePlay::collisionCiudad(PersonajePrincipal& p, sf::RectangleShape paso, sf::RenderWindow* window, Enemigo& e) {
	if (p.setCollisionPj().getGlobalBounds().intersects(paso.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= paso.getPosition().y) {//BAJANDO
				window->clear();
				mostrarVentana(window, e, p, 450, 30);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= paso.getPosition().y) {//SUBIENDO
				window->clear();
				mostrarVentana(window, e, p, 450, 30);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= paso.getPosition().x) {//YENDO DERECHA
				window->clear();
			    mostrarVentana(window, e, p, 450, 30);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= paso.getPosition().x) {//YENDO IZQUIERDA
				window->clear();
				mostrarVentana(window, e, p, 450, 30);
			}
			break;
		case 0:
			break;
		}
	}
}