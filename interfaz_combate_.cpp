#include"interfaz_combate.h"
#include "turno.h"
#include "Mazo.h"

void combate::procesar_eventos(sf::RenderWindow * window, sf::Vector2f posicion,turno t, Enemigo& e, PersonajePrincipal& p,Mazo &m) {
	sf::Event evento;
	
	cout << e.get_vida();
	while (window->pollEvent(evento)) {
		if (atacar == false) {
			switch (evento.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					if (posicion.y == 651) {
						sprite_boton->setPosition(81, 560);
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (posicion.y == 560) {
						sprite_boton->setPosition(81, 651);
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					if (posicion.y == 560) {
						atacar = true;
						sprite_boton->setPosition(81, 555);
						sprite_boton->setScale(0.4f, 0.4f);
					}
					else {
						huir = true;
						break;
					}
				}
				break;
			}
		}
		else {
			switch (evento.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					switch ((int)posicion.y) {
					case 555:
						sprite_boton->setPosition(81, 555);
					break;
					case 590:
						sprite_boton->setPosition(81, 555);
					break;
					case 625:
						sprite_boton->setPosition(81, 590);
					break;
					case 664:
						sprite_boton->setPosition(81, 625);
					break;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					switch ((int)posicion.y) {
					case 664:
						sprite_boton->setPosition(81, 664);
						//carta 4
					break;
					case 625:
						sprite_boton->setPosition(81, 664);
						//carta 3
					break;
					case 590:
						sprite_boton->setPosition(81, 625);
						//carta 2
					break;
					case 555:
						sprite_boton->setPosition(81, 590);
						//carta 1
					break;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

					switch ((int)posicion.y) {
					case 555:
						
						t.elegir_carta(0);
					
						break;
					case 590:
						t.elegir_carta(1);
						
						break;
					case 625:
						t.elegir_carta(2);
					
						break;
					case 664:
						t.elegir_carta(3);
						
						break;
					}
					//cout << "";
					atacar = false;/// cout << "";
					sprite_boton->setPosition(81, 560);
					sprite_boton->setScale(0.5f, 0.5f);
					//cout << "";
					cout << e.get_vida();
					t.efecto_de_carta(e, p,m); 
					t.combate(e, p, m);
					vida_enemigo = e.get_vida();
					vida_personaje = p.get_vida();
					m.cambiar(t.get_elecion());

				}
				break;
			}
		}

	}
}

void combate::setFont() {

	fuente_combate = new sf::Font();
	fuente_combate->loadFromFile("Enchanted_Land.otf");

}

void combate::definir_vida() {
	
	/*vida_personaje = new sf::RectangleShape(sf::Vector2f(126, 10));
	vida_personaje->setPosition(270, 342);
	vida_personaje->setFillColor(sf::Color::Green);

	vida_enemigo = new sf::RectangleShape(sf::Vector2f(126, 10));
	vida_enemigo->setPosition(631, 103);
	vida_enemigo->setFillColor(sf::Color::Green);*/
}

void combate::setTexture_combate(Enemigo& e/*, PersonajePrincipal& k*/) {

	textura_combate = new sf::Texture();
	textura_combate->loadFromFile("Graphics\\combate.png");

	textura_vida = new sf::Texture();
	textura_vida->loadFromFile("Graphics\\vida.png");

	textura_opcion = new sf::Texture();
	textura_opcion->loadFromFile("Graphics\\opcion.png");

	textura_personaje = new sf::Texture();
	textura_personaje->loadFromFile("Graphics\\closter.png");

	//textura_enemigo = new sf::Texture();
	//textura_enemigo->loadFromFile("Graphics\\mj.png");
	e.setDragon();
	e.getDragon();

	textura_fondo = new sf::Texture();
	textura_fondo->loadFromFile("Graphics\\mapa_combate.png");

	textura_boton = new sf::Texture();
	textura_boton->loadFromFile("Graphics\\boton.png");
}

void combate::setSprite_combate() {

	sprite_combate = new sf::Sprite(*textura_combate);
	sprite_combate->setPosition(410, 482);
	sprite_combate->setScale(2.25f, 2.49f);

	sprite_vida = new sf::Sprite(*textura_vida);
	sprite_vida->setPosition(260, 300);
	sprite_vida->setScale(0.7f, 0.7f);
	sprite_vida->setColor(sf::Color::Color(248,248,255));

	sprite_vida_enemigo = new sf::Sprite(*textura_vida);
	sprite_vida_enemigo->setPosition(620, 60);
	sprite_vida_enemigo->setScale(0.7f, 0.7f);
	sprite_vida_enemigo->setColor(sf::Color::Color(248,248,255));

	sprite_opcion = new sf::Sprite(*textura_opcion);
	sprite_opcion->setPosition(60, 539);
	sprite_opcion->setScale(0.8f, 0.8f);

	sprite_fondo = new sf::Sprite(*textura_fondo);

	sprite_boton = new sf::Sprite(*textura_boton);
	sprite_boton->setPosition(81, 560);
	sprite_boton->setScale(0.5f, 0.5f);
}

void combate::setSprite_pj(Enemigo e) {

	sprite_personaje = new sf::Sprite(*textura_personaje);
	sprite_personaje->setPosition(120, 329);

	sprite_enemigo = new sf::Sprite(e.getDragon());
	sprite_enemigo->setPosition(300, 20);
	sprite_enemigo->setColor(sf::Color::White);

}

sf::Text combate::setTexto(sf::String texto, unsigned int tamaño_texto, sf::Vector2f ubicacion, float grueso) {
	sf::Text* txt_menu;

	txt_menu = new sf::Text();
	txt_menu->setFont(*fuente_combate);

	txt_menu->setString(texto);
	txt_menu->setCharacterSize(tamaño_texto);
	txt_menu->setPosition(ubicacion);
	txt_menu->setFillColor(sf::Color::White);
	txt_menu->setOutlineThickness(grueso);
	txt_menu->setOutlineColor(sf::Color::Black);

	return *txt_menu;
}

void combate::iniciar_pelea(sf::RenderWindow* window, Enemigo& e, PersonajePrincipal& p) {
	vida_personaje = 50;
	vida_enemigo = 50;

	setFont();
	setTexture_combate(e);
	setSprite_combate();
	setSprite_pj(e);
	definir_vida();

	sprite_fondo->setScale((float)window->getSize().x / sprite_fondo->getTexture()->getSize().x, (float)window->getSize().y / sprite_fondo->getTexture()->getSize().y);
	sf::Text* txt_ataque, * txt_huir, * txt_carta1, * txt_carta2, * txt_carta3, * txt_carta4, * txt_desc;
	sf::Text* txt_vida_p, * txt_vida_e, * txt_vida_p_total, * txt_vida_e_total, * barra, * barra2;
	txt_ataque = new sf::Text();
	txt_huir = new sf::Text();
	txt_carta1 = new sf::Text();
	txt_carta2 = new sf::Text();
	txt_carta3 = new sf::Text();
	txt_carta4 = new sf::Text();
	txt_desc = new sf::Text();
	txt_vida_p = new sf::Text();
	txt_vida_p->setFont(*fuente_combate);
	txt_vida_e = new sf::Text();
	txt_vida_e->setFont(*fuente_combate);
	txt_vida_p_total = new sf::Text();
	txt_vida_p_total->setFont(*fuente_combate);
	txt_vida_e_total = new sf::Text();
	txt_vida_e_total->setFont(*fuente_combate);
	barra = new sf::Text();
	barra->setFont(*fuente_combate);
	barra2 = new sf::Text();
	barra2->setFont(*fuente_combate);

	*txt_ataque = setTexto("Atacar", 45, { 132, 550 }, 5);
	*txt_huir = setTexto("Huir", 45, { 132, 640 }, 5);
	*txt_carta1 = setTexto("Carta 1", 35, { 132, 550 }, 5);
	*txt_carta2 = setTexto("Carta 2", 35, { 132, 585 }, 5);
	*txt_carta3 = setTexto("Carta 3", 35, { 132, 620 }, 5);
	*txt_carta4 = setTexto("Carta 4", 35, { 132, 660 }, 5);
	*txt_desc = setTexto("¿Que deseas hacer?", 45, { 560, 600 }, 5);
	*barra = setTexto("/", 16, { 326, 336 }, 2);
	*barra2 = setTexto("/", 16, { 690, 97 }, 2);

	txt_vida_p->setString(to_string(vida_personaje));
	txt_vida_p->setPosition(303, 326);
	txt_vida_p_total->setString(to_string(vida_personaje));
	txt_vida_p_total->setPosition(340, 326);

	txt_vida_e->setString(to_string(vida_enemigo));
	txt_vida_e->setPosition(668, 87);
	txt_vida_e_total->setString(to_string(vida_enemigo));
	txt_vida_e_total->setPosition(703, 87);

	sf::RectangleShape contorno_vida_personaje(sf::Vector2f(128, 12));
	contorno_vida_personaje.setFillColor(sf::Color::Transparent);
	contorno_vida_personaje.setPosition(269, 341);
	contorno_vida_personaje.setOutlineThickness(3);
	contorno_vida_personaje.setOutlineColor(sf::Color::Black);

	sf::RectangleShape contorno_vida_enemigo(sf::Vector2f(128, 12));
	contorno_vida_enemigo.setFillColor(sf::Color::Transparent);
	contorno_vida_enemigo.setPosition(630, 102);
	contorno_vida_enemigo.setOutlineThickness(3);
	contorno_vida_enemigo.setOutlineColor(sf::Color::Black);


	Mazo m;

	txt_carta1 = new sf::Text();
	txt_carta2 = new sf::Text();
	txt_carta3 = new sf::Text();
	txt_carta4 = new sf::Text();

	txt_carta1->setFont(*fuente_combate);
	txt_carta2->setFont(*fuente_combate);
	txt_carta3->setFont(*fuente_combate);
	txt_carta4->setFont(*fuente_combate);

	m.cargar_mano();

	txt_carta1->setString(m.nombre_carta(m, 0));
	txt_carta2->setString(m.nombre_carta(m, 1));
	txt_carta3->setString(m.nombre_carta(m, 2));
	txt_carta4->setString(m.nombre_carta(m, 3));

	txt_carta1->setPosition(132, 550);
	txt_carta2->setPosition(132, 585);
	txt_carta3->setPosition(132, 620);
	txt_carta4->setPosition(132, 660);


	sf::Text* txt_desc_carta1, * danio, * HP, * danio_dragon;
	Carta cart;

	txt_desc_carta1 = new sf::Text();
	danio = new sf::Text();
	danio->setFont(*fuente_combate);
	danio_dragon = new sf::Text();
	danio_dragon->setFont(*fuente_combate);
	HP = new sf::Text();

	m.set_mano();

	while (p.get_vida() > 0 && e.get_vida() > 0 && huir == false && window->isOpen()) {
		//window->clear();
		sf::Vector2f posicion = sprite_boton->getPosition();
		cout << e.get_vida();
		window->draw(*sprite_fondo);
		window->draw(*sprite_personaje);
		window->draw(*sprite_enemigo);
		window->draw(*sprite_opcion);
		window->draw(*sprite_combate);
		window->draw(*txt_desc_carta1);
		window->draw(*txt_carta1);
		window->draw(*txt_carta2);
		window->draw(*txt_carta3);
		window->draw(*txt_carta4);



		procesar_eventos(window, posicion, t, e, p, m);


		if (atacar == false) {





			txt_carta1->setString(m.nombre_carta(m, 0));
			txt_carta2->setString(m.nombre_carta(m, 1));
			txt_carta3->setString(m.nombre_carta(m, 2));
			txt_carta4->setString(m.nombre_carta(m, 3));
			danio->setString(" ");
			HP->setString(" ");
			window->clear();
			window->draw(*sprite_fondo);
			window->draw(*sprite_personaje);
			window->draw(*sprite_enemigo);
			window->draw(*sprite_opcion);
			window->draw(*sprite_combate);
			window->draw(*txt_ataque);
			window->draw(*txt_desc);
			window->draw(*txt_huir);
			txt_vida_p->setString(to_string(vida_personaje));
			txt_vida_e->setString(to_string(vida_enemigo));


		}
		else {
			switch ((int)posicion.y) {
			case 555:
				cart = m.get_mano(0);
				danio->setString(" ");
				HP->setString(" ");
				if (cart.get_stun() == true) {
					*txt_desc_carta1 = setTexto("Esta carta aturde al enemigo", 45, { 540,600 }, 5);
				}
				else if (cart.get_afectaPersonaje() == true) {
					*txt_desc_carta1 = setTexto("Esta carta cura al personaje", 45, { 540,600 }, 5);
				}
				else {
					*txt_desc_carta1 = setTexto("Esta carta inflinge daño al enemigo de", 40, { 463,600 }, 5);
					*HP = setTexto("HP", 37, { 879,600 }, 5);
					danio->setString(to_string(-cart.get_valor()));
					danio->setPosition({ 853, 600 });
					danio->setCharacterSize(40);
					danio->setOutlineThickness(5);
					danio->setOutlineColor(sf::Color::Black);
				}
				break;
			case 590:
				cart = m.get_mano(1);
				danio->setString(" ");
				HP->setString(" ");
				if (cart.get_stun() == true) {
					*txt_desc_carta1 = setTexto("Esta carta aturde al enemigo", 45, { 540,600 }, 5);
				}
				else if (cart.get_afectaPersonaje() == true) {
					*txt_desc_carta1 = setTexto("Esta carta cura al personaje", 45, { 540,600 }, 5);
				}
				else {
					*txt_desc_carta1 = setTexto("Esta carta inflinge daño al enemigo de", 40, { 463,600 }, 5);
					*HP = setTexto("HP", 37, { 879,600 }, 5);
					danio->setString(to_string(-cart.get_valor()));
					danio->setPosition({ 853, 600 });
					danio->setCharacterSize(40);
					danio->setOutlineThickness(5);
					danio->setOutlineColor(sf::Color::Black);
				}
				break;
			case 625:
				cart = m.get_mano(2);
				danio->setString(" ");
				HP->setString(" ");
				if (cart.get_stun() == true) {
					*txt_desc_carta1 = setTexto("Esta carta aturde al enemigo", 45, { 540,600 }, 5);
				}
				else if (cart.get_afectaPersonaje() == true) {
					*txt_desc_carta1 = setTexto("Esta carta cura al personaje", 45, { 540,600 }, 5);
				}
				else {
					*txt_desc_carta1 = setTexto("Esta carta inflinge daño al enemigo de", 40, { 463,600 }, 5);
					*HP = setTexto("HP", 37, { 879,600 }, 5);
					danio->setString(to_string(-cart.get_valor()));
					danio->setPosition({ 853, 600 });
					danio->setCharacterSize(40);
					danio->setOutlineThickness(5);
					danio->setOutlineColor(sf::Color::Black);
				}
				break;
			case 664:
				cart = m.get_mano(3);
				danio->setString(" ");
				HP->setString(" ");
				if (cart.get_stun() == true) {
					*txt_desc_carta1 = setTexto("Esta carta aturde al enemigo", 45, { 540,600 }, 5);
				}
				else if (cart.get_afectaPersonaje() == true) {
					*txt_desc_carta1 = setTexto("Esta carta cura al personaje", 45, { 540,600 }, 5);
				}
				else {
					*txt_desc_carta1 = setTexto("Esta carta inflinge daño al enemigo de", 40, { 463,600 }, 5);
					*HP = setTexto("HP", 37, { 879,600 }, 5);
					danio->setString(to_string(-cart.get_valor()));
					danio->setPosition({ 853, 600 });
					danio->setCharacterSize(40);
					danio->setOutlineThickness(5);
					danio->setOutlineColor(sf::Color::Black);
				}
				break;
			}
			window->draw(*danio);
			window->draw(*HP);
			/*window->draw(*txt_carta1);
			window->draw(*txt_carta2);
			window->draw(*txt_carta3);
			window->draw(*txt_carta4);*/
		}
		window->draw(*sprite_boton);
		window->draw(*sprite_vida);
		window->draw(*sprite_vida_enemigo);
		window->draw(*barra);
		window->draw(*barra2);
		window->draw(*txt_vida_p);
		window->draw(*txt_vida_e);
		window->draw(*txt_vida_p_total);
		window->draw(*txt_vida_e_total);
		//window->draw(contorno_vida_personaje);
		//window->draw(contorno_vida_enemigo);

		window->display();
	}

}