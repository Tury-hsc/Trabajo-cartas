#include <iostream>
using namespace std; 
#include "Enemigo.h"
#include "Carta.h"
#include "Mazo.h"
#include "PersonajePrincipal.h"
#include "turno.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include  "gamePlay.h"
#include "menu.h"
#include"Texto.h"

/*
int main()
{
  
	PersonajePrincipal personaje(20,15,9,7);
	Enemigo enemigo(40, 14, 14, 5);
	Mazo mazo;
	turno t;
	cout <<"e:"<< enemigo.get_vida()<<endl;
	cout <<"p:"<< personaje.get_vida()<<endl;
	mazo.cargar_mano();
	mazo.set_mano();
	t.combate_mientras(enemigo, personaje, mazo);
   



}*/


int main()
{
	
	//Carta carta;
	//carta.crear_carta();

	/*Texto texto;
	texto.setTexto();
	texto.mostrarTexto();*/

	Enemigo e(50,10,1,1);
	PersonajePrincipal p(50,11,1,1);
	menu i;
	i.mostrar_menu(e,p);
	
	

	return 0;

}