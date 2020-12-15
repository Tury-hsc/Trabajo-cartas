#include "menu.h"
#include<iostream>
#include "turno.h"
#include "Enemigo.h"
#include "PersonajePrincipal.h"
#include "mazo.h"

void menu::eventos(sf::Vector2f posicion, Enemigo& e, PersonajePrincipal& p) {
	while (window->pollEvent(*evento)){
		switch (evento->type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (posicion.y == 579) {
					rectangulo_seleccion->setPosition(396, 457);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (posicion.y == 457) {
					rectangulo_seleccion->setPosition(396, 579);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				if (posicion.y == 457) {
					window->clear();
					_musicaFondo->stop();
					gamePlay juego;
					juego.mostrarVentana(window,e,p,500,500);
				}
				else {
					_musicaFondo->stop();
					window->close();
					break;
				}
			}
			break;
		}
	}
}

void menu::setTexture_iconos() {

	textura_iconos = new sf::Texture();
	textura_iconos->loadFromFile("Graphics\\iconosmenu.png");

	textura_tabla = new sf::Texture();
	textura_tabla->loadFromFile("Graphics\\tabla.png");

	textura_cadena = new sf::Texture();
	textura_cadena->loadFromFile("Graphics\\cadena.png");
}

void menu::setSprite_iconos() {
	sf::Vector2u tamIconos = sf::Vector2u(textura_iconos->getSize());
	tamIconos.x /= 3;
	tamIconos.y /= 2;

	sprite_iconos = new sf::Sprite(*textura_iconos);

	sprite_iconos->setTextureRect(sf::IntRect(0,0, tamIconos.x, tamIconos.y));
	sprite_iconos->setPosition(297, 314);
	sprite_iconos->setScale(1.8f, 1.8f);

	tabla = new sf::Sprite(*textura_tabla);
	tabla->setPosition(344, 50);
	tabla->setScale(1.01f, 1.01f);

	cadena1 = new sf::Sprite(*textura_cadena);
	cadena1->setPosition(398, 264);
	cadena1->setScale(0.45f, 0.45f);

	cadena2 = new sf::Sprite(*textura_cadena);
	cadena2->setPosition(598, 264);
	cadena2->setScale(0.45f, 0.45f);
}

void menu::setSprite() {

	sprite_fondo = new sf::Sprite(*textura_fondo);

	sprite_fondo->setScale((float)window->getSize().x / sprite_fondo->getTexture()->getSize().x, (float)window->getSize().y / sprite_fondo->getTexture()->getSize().y);
}

void menu::setTexture() {

	textura_fondo = new sf::Texture();
	textura_fondo->loadFromFile("Graphics\\fondomenu.jpg");

}

void menu::setFont(sf::String fuente_texto) {

	fuente = new sf::Font;
	fuente->loadFromFile(fuente_texto);

}

void menu::definir_rectangulo() {

	rectangulo_seleccion = new sf::RectangleShape(sf::Vector2f(230, 50));
	rectangulo_seleccion->setPosition(396,457);
	rectangulo_seleccion->setOutlineColor(sf::Color::Blue);
	rectangulo_seleccion->setOutlineThickness(5);
	rectangulo_seleccion->setFillColor(sf::Color::Transparent);
}

sf::Text menu::setTexto(sf::String texto, unsigned int tamaño_texto, sf::Vector2f ubicacion) {
	sf::Text* txt_menu;

	txt_menu = new sf::Text();
	txt_menu->setFont(*fuente);

	txt_menu->setString(texto);
	txt_menu->setCharacterSize(tamaño_texto);
	txt_menu->setPosition(ubicacion);
	txt_menu->setFillColor(sf::Color::White);
	txt_menu->setOutlineThickness(5);
	txt_menu->setOutlineColor(sf::Color::Black);

	return *txt_menu;
}

void menu::mostrar_menu(Enemigo& e, PersonajePrincipal& p) {

	window = new sf::RenderWindow (sf::VideoMode(1024, 720), "PROYECTO", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);

	evento = new sf::Event();

	sf::String fuente_texto = "fuente.ttf";
	sf::Text *txt_menu, *txt_opcion1, *txt_opcion2, *txt_menu2;
	txt_menu = new sf::Text();
	txt_menu2 = new sf::Text();
	txt_opcion1 = new sf::Text();
	txt_opcion2 = new sf::Text();

	setFont(fuente_texto);
	*txt_menu = setTexto("Nombre del", 50, {398, 60});
	*txt_menu2 = setTexto("Juego", 50, { 446,159 });
	*txt_opcion1 = setTexto("Comenzar Juego", 38, { 399, 457 });
	*txt_opcion2 = setTexto("Salir del juego", 38, { 411, 579 });
	setTexture_iconos();
	setSprite_iconos();

	_musicaFondo = new sf::Music();//va a cagar el buffer
	//cargamos buffer
	if (!_musicaFondo->openFromFile("musica\\menu.wav")) {
		std::cout << "No se pudo cargar el sonido" << std::endl;
	}

	definir_rectangulo();
	setTexture();
	setSprite();
	_musicaFondo->setVolume(10);
	_musicaFondo->play();

	while (window->isOpen()) {
		sf::Vector2f ubicacion_rectangulo = rectangulo_seleccion->getPosition();
		eventos(ubicacion_rectangulo,e,p);
		
		window->clear();
		window->draw(*sprite_fondo);
		window->draw(*sprite_iconos);
		window->draw(*tabla);
		window->draw(*cadena1);
		window->draw(*cadena2);
		window->draw(*txt_menu);
		window->draw(*txt_menu2);
		window->draw(*txt_opcion1);
		window->draw(*txt_opcion2);
		window->draw(*rectangulo_seleccion);
		window->display();
	}
	_musicaFondo->stop();
}