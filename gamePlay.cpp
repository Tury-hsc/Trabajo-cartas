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

void gamePlay::mostrarVentana(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p)
{
	
	window->setFramerateLimit(60);


	sf::Music _musicaFondo;
	
	if (!_musicaFondo.openFromFile("musica\\pelea3.wav")) {
		std::cout << "No se pudo cargar el sonido" << std::endl;
	}

	mapaPrincipal.setTextureMap();
	mapaPrincipal.setMap();

	_musicaFondo.play();
	_musicaFondo.setVolume(20);

	e.setTextureDragon();
	e.setDragon();
	e.setScaleDragon();


	while (window->isOpen())
	{
		sf::Event event;		
		
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
		
		collisionMapa(p);
		collisionObjetos(p, e, window);

		p.moverPj(frame, x, y);

		window->draw(mapaPrincipal.getMap());
		window->draw(e.getDragon());
		window->draw(e.setCollisionDragon());
		window->draw(p.setCollisionPj());
		window->draw(p.getPlayer());		
		window->display();
		frame += .2f;
	}
	_musicaFondo.stop();
}



