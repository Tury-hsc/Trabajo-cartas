#pragma once
#include <iostream>
#include "Carta.h"
#include <vector>
#include  "gamePlay.h"
using namespace std;

class Mazo
{	
	int _cantidad;
	vector <Carta> Mano;
	Carta _mano[4];



public:
	
	Mazo();
	void size_mazo();
	void cargar_mano();
	int get_cantidad ();
	int cantida_de_cartas ();
	void set_cantidad();
	void set_mano();
	char * nombre_carta(Mazo &a,int x);
	Carta get_mano(int x);
	void cambiar(int x);
};


