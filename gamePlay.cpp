#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include "Enemigo.h"
#include "mapa.h"
#include "PersonajePrincipal.h"
#include "gamePlay.h"
#include "interfaz_combate.h"
//p(40,20,20,20) , e (30,10,20,20)
gamePlay::gamePlay() {

	frame = 0;
	x = 0;
	y = 0;

}



void gamePlay::collisionObjetos()
{

}

void gamePlay::collisionMapa()
{
}

void gamePlay::mostrarVentana(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p)
{
	
	window->setFramerateLimit(60);


	sf::Music _musicaFondo; //va a cagar el buffer
	//cargamos buffer
	if (!_musicaFondo.openFromFile("musica\\pelea3.wav")) {
		std::cout << "No se pudo cargar el sonido" << std::endl;
	}

	mapaPrincipal.setTextureMap();
	mapaPrincipal.setMap();

	/*kloster.setTexturePlayer();
	kloster.setPlayer(500.0f, 500.0f);*/


	_musicaFondo.play();
	_musicaFondo.setVolume(0);

	e.setTextureDragon();
	e.setDragon();
	e.setScaleDragon();


	while (window->isOpen())
	{
		sf::Event event;
		sf::RectangleShape collisionDragon = e.setCollisionDragon();
		sf::RectangleShape collisionPj = p.setCollisionPj();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			window->clear();
			combate pelea;
			pelea.iniciar_pelea(window, e, p);
		}
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed) {
				
			}
		}

		if (collisionPj.getGlobalBounds().intersects(collisionDragon.getGlobalBounds())) {	
			combate pelea;
			switch (p.getEstado()) {
			case 2:
				if (collisionPj.getPosition().y <= collisionDragon.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
				
				pelea.iniciar_pelea(window, e, p);
				}
				break;
			case 1:
				if (collisionPj.getPosition().y >= collisionDragon.getPosition().y) {//SUBIENDO
					p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
					
				pelea.iniciar_pelea(window, e, p);
				}
				break;
			case 3:
				if (collisionPj.getPosition().x <= collisionDragon.getPosition().x) {//YENDO DERECHA
					p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
					pelea.iniciar_pelea(window, e, p);
				}
				break;
			case 4:
				if (collisionPj.getPosition().x >= collisionDragon.getPosition().x) {//YENDO IZQUIERDA
					p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
					pelea.iniciar_pelea(window, e, p);
				}
				break;
			case 0:
				break;
			}
		}

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

		p.moverPj(frame, x, y);

		window->draw(mapaPrincipal.getMap());
		window->draw(e.getDragon());
		window->draw(collisionDragon);
		window->draw(collisionPj);
		window->draw(p.getPlayer());
		//window->draw(_arbol);
		//window->draw(_arbol2);
		//window->draw(_arbol3);
		//window->draw(_dungeon);
		window->display();
		frame += .2f;
	}
	_musicaFondo.stop();
}



