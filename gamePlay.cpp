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
#include"menu.h"

//p(40,20,20,20) , e (30,10,20,20)
gamePlay::gamePlay() {
	frame = 0;
	x = 0;
	y = 0;
}

void gamePlay::setCuadroDialogo() {

	textura_dialogo = new sf::Texture();
	textura_dialogo->loadFromFile("Graphics\\tabla.png");

	dialogo = new sf::Sprite(*textura_dialogo);
	dialogo->setScale(3.2f, 0.5f);
	dialogo->setPosition(7, 580);

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
		if (p.setCollisionPj().getPosition().x >= 655 && p.setCollisionPj().getPosition().x <= 705) {
			window->draw(*dialogo);
			window->draw(np.getText());
			window->draw(np.getTextNombre());
		}
	}
}

void gamePlay::mostrarVentana(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p, float posx, float posy)
{	
	
	if (!_musicaFondo.openFromFile("musica\\pelea3.wav")) {
		std::cout << "No se pudo cargar el sonido" << std::endl;
	}
	
	Texto ff;

	char a[300];
	strcpy(a, ff.obtenerTexto(0));

	npc np("Brian Lara", a, "Enchanted_Land.otf");

	np.setTextureNpc();
	np.setNpc(674, 460);

	setCuadroDialogo();

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

		collisionParteDerechaAbajo(p);
		collisionParteDerecha(p);
		collisionSillas(p);
		collisionPlantas(p);
		collisionFuente(p);
		collisionCerca(p);
		collisionMapa(p);	
		collisionBosque(p, paso, window, e);
		p.moverPj(frame, x, y);
		window->draw(ciudad.getMap());
		//window->draw(paso);	
		window->draw(p.setCollisionPj());
		window->draw(p.getPlayer());
		window->draw(np.getNpc());
		//window->draw(np.setCollisionNpc(680, 540));
		collisionNpc(p, np, window);
		window->display();
		frame += .2f;
	}
	_musicaFondo.stop();
}

void gamePlay::mapa2(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p, float posx, float posy)
{
	
	menu i;
	dungeon d;
	
	sf::RectangleShape paso;
	paso.setSize({ 50,20 });
	paso.setFillColor(sf::Color::Black);
	paso.setPosition(478, 700);

	mapaPrincipal.setTextureMap("Graphics\\mapa.png");
	mapaPrincipal.setMap(500, 250);

	mapaPrincipal.setTextureMap("Graphics\\mapa.png");
	mapaPrincipal.setMap(550, 300);

	p.setPlayer(posx, posy);

	textura_ganaste = new sf::Texture();
	textura_ganaste->loadFromFile("Graphics\\bictoria.png");

	textura_perdiste = new sf::Texture();
	textura_perdiste->loadFromFile("Graphics\\derota.png");

	sprite_ganaste = new sf::Sprite(*textura_ganaste);
	sprite_ganaste->setScale((float)window->getSize().x / sprite_ganaste->getTexture()->getSize().x, (float)window->getSize().y / sprite_ganaste->getTexture()->getSize().y);
	sprite_perdiste = new sf::Sprite(*textura_perdiste);
	sprite_perdiste->setScale((float)window->getSize().x / sprite_perdiste->getTexture()->getSize().x, (float)window->getSize().y / sprite_perdiste->getTexture()->getSize().y);

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
		//window->draw(paso);
		window->draw(d.getDungeon());
		window->draw(d.setCollisionDg());		
		window->draw(p.setCollisionPj());
		window->draw(p.getPlayer());

		if (p.get_vida() <= 0) {
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) {
				window->draw(*sprite_perdiste);
			}
			else {
				p.set_vida(50);
				e.set_vida(50);
				_musicaFondo.stop();
				window->close();
				i.mostrar_menu(e, p);
			}
		}
		else if (e.get_vida() <= 0) {
			if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) {
				window->draw(*sprite_ganaste);
			}
			else {
				p.set_vida(50);
				e.set_vida(50);
				_musicaFondo.stop();
				window->close();
				i.mostrar_menu(e, p);
			}
		}
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

void gamePlay::collisionParteDerechaAbajo(PersonajePrincipal& p) {

	sf::RectangleShape parte1;
	parte1.setSize({ 9,95 });
	parte1.setFillColor(sf::Color::Black);
	parte1.setPosition(685, 450);

	sf::RectangleShape parte2;
	parte2.setSize({ 50,43 });
	parte2.setFillColor(sf::Color::Black);
	parte2.setPosition(565, 475);

	sf::RectangleShape parte3;
	parte3.setSize({ 25,24 });
	parte3.setFillColor(sf::Color::Black);
	parte3.setPosition(745, 500);

	if (p.setCollisionPj().getGlobalBounds().intersects(parte1.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte1.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte1.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte1.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte1.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(parte2.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte2.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte2.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte2.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte2.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(parte3.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte3.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte3.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte3.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte3.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	
}

void gamePlay::collisionParteDerecha(PersonajePrincipal& p) {
	
	sf::RectangleShape parte1;
	parte1.setSize({ 1,250 });
	parte1.setFillColor(sf::Color::Black);
	parte1.setPosition(570, 120);

	sf::RectangleShape parte2;
	parte2.setSize({ 1,250 });
	parte2.setFillColor(sf::Color::Black);
	parte2.setPosition(810, 120);

	sf::RectangleShape parte3;
	parte3.setSize({ 179,30 });
	parte3.setFillColor(sf::Color::Black);
	parte3.setPosition(600, 160);

	sf::RectangleShape parte4;
	parte4.setSize({ 179,30 });
	parte4.setFillColor(sf::Color::Black);
	parte4.setPosition(600, 350);

	if (p.setCollisionPj().getGlobalBounds().intersects(parte1.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte1.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte1.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte1.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte1.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(parte2.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte2.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte2.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte2.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte2.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(parte3.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte3.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte3.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte3.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte3.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(parte4.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= parte4.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= parte4.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= parte4.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= parte4.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
}

void gamePlay::collisionSillas(PersonajePrincipal& p) {
	
	sf::RectangleShape rio;
	rio.setSize({ 10,100 });
	rio.setFillColor(sf::Color::Black);
	rio.setPosition(275, 230);

	sf::RectangleShape rio_arriba;
	rio_arriba.setSize({ 10,100 });
	rio_arriba.setFillColor(sf::Color::Black);
	rio_arriba.setPosition(370, 230);

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

void gamePlay::collisionPlantas(PersonajePrincipal& p) {
	sf::RectangleShape planta1;
	planta1.setSize({ 79,20 });
	planta1.setFillColor(sf::Color::Black);
	planta1.setPosition(216, 372);

	sf::RectangleShape planta2;
	planta2.setSize({ 71,20 });
	planta2.setFillColor(sf::Color::Black);
	planta2.setPosition(367, 372);

	sf::RectangleShape planta3;
	planta3.setSize({ 210,20 });
	planta3.setFillColor(sf::Color::Black);
	planta3.setPosition(222, 179);

	if (p.setCollisionPj().getGlobalBounds().intersects(planta1.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= planta1.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= planta1.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= planta1.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= planta1.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(planta2.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= planta2.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= planta2.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= planta2.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= planta2.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}

	if (p.setCollisionPj().getGlobalBounds().intersects(planta3.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= planta3.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= planta3.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= planta3.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= planta3.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
}

void gamePlay::collisionFuente(PersonajePrincipal& p) {
	
	/*sf::RectangleShape fuente;
	fuente.setSize({ 190,185 });
	fuente.setFillColor(sf::Color::Black);
	fuente.setPosition(213, 450);*/

	sf::CircleShape fuente(80, 70);
	fuente.setFillColor(sf::Color::Black);
	fuente.setPosition(225, 470);

	if (p.setCollisionPj().getGlobalBounds().intersects(fuente.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= fuente.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= fuente.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= fuente.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= fuente.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}


	
}

void gamePlay::collisionCerca(PersonajePrincipal& p) {
	sf::RectangleShape cerca1;
	cerca1.setSize({ 20,700 });
	cerca1.setFillColor(sf::Color::Black);
	cerca1.setPosition(64, 30);

	sf::RectangleShape cerca2;
	cerca2.setSize({ 20,700 });
	cerca2.setFillColor(sf::Color::Black);
	cerca2.setPosition(960, 30);

	sf::RectangleShape cerca3;
	cerca3.setSize({ 285,20 });
	cerca3.setFillColor(sf::Color::Black);
	cerca3.setPosition(101, 693);

	sf::RectangleShape cerca4;
	cerca4.setSize({ 385,20 });
	cerca4.setFillColor(sf::Color::Black);
	cerca4.setPosition(560, 693);

	if (p.setCollisionPj().getGlobalBounds().intersects(cerca1.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= cerca1.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= cerca1.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= cerca1.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= cerca1.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(cerca2.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= cerca2.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= cerca2.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= cerca2.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= cerca2.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(cerca3.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= cerca3.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= cerca3.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= cerca3.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= cerca3.getPosition().x) {//YENDO IZQUIERDA
				p.setPlayer(p.getPosition().x + 4.0f, p.getPosition().y);
			}
			break;
		case 0:
			break;
		}
	}
	if (p.setCollisionPj().getGlobalBounds().intersects(cerca4.getGlobalBounds())) {
		switch (p.getEstado()) {
		case 2:
			if (p.setCollisionPj().getPosition().y <= cerca4.getPosition().y) {//BAJANDO
				p.setPlayer(p.getPosition().x, p.getPosition().y - 4.0f);
			}
			break;
		case 1:
			if (p.setCollisionPj().getPosition().y >= cerca4.getPosition().y) {//SUBIENDO
				p.setPlayer(p.getPosition().x, p.getPosition().y + 4.0f);
			}
			break;
		case 3:
			if (p.setCollisionPj().getPosition().x <= cerca4.getPosition().x) {//YENDO DERECHA
				p.setPlayer(p.getPosition().x - 4.0f, p.getPosition().y);
			}
			break;
		case 4:
			if (p.setCollisionPj().getPosition().x >= cerca4.getPosition().x) {//YENDO IZQUIERDA
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
		case 0:
			break;
		}
	}
}