#pragma once
#include "Enemigo.h"
#include "PersonajePrincipal.h"
#include "Mazo.h"

class turno
{
private:
	int _elecion,_turno;
	int _suma;

public:
	
	void set0();
	void set_turno();
	int get_turno();
	void elegir_carta(int x);
	int get_elecion();
	void efecto_de_carta(Enemigo &e,PersonajePrincipal &p,Mazo &m);
	void combate(Enemigo &e, PersonajePrincipal &p, Mazo &m);
	void combate_mientras(Enemigo &e, PersonajePrincipal &p, Mazo &m);

};

