#include "turno.h"

void turno::set0()
{
	_turno = 0;
}

void turno::set_turno()
{
	_turno++;
}

int turno::get_turno()
{
	return _turno;
}

void turno::elegir_carta(int x)
{
	_elecion = x;
}

int turno::get_elecion()
{
	return _elecion;
}



void turno::efecto_de_carta(Enemigo& e, PersonajePrincipal& p, Mazo& m)
{
	Carta c;
	cout << "peru" << c.get_valor() << "peru";
	cout << "peru" << c.get_nombre() << "peru";
	cout << "e:" << e.get_vida() << endl;
	c = m.get_mano(get_elecion());
	if (c.get_afectaPersonaje() == true)
	{
		p.modificar_vida(c.get_valor());
		p.set_pierdeturno(c.get_stun());
	}
	else
	{
		cout << "peru" << c.get_valor() << "peru";
		e.modificar_vida(c.get_valor());
		e.set_pierdeturno(c.get_stun());
	}
	cout << "e:" << e.get_vida() << endl;
	cout << "p:" << p.get_vida() << endl;
}

void turno::combate(Enemigo& e, PersonajePrincipal& p, Mazo& m)
{
	if (e.get_pierdeturno()) {
		e.set_pierdeturno(false);
	}
	else
	{
		
		p.modificar_vida(e.danio_a_personaje());
	}

}

void turno::combate_mientras(Enemigo& e, PersonajePrincipal& p, Mazo& m)
{

	set0();
	do
	{

		set_turno();
		combate(e, p, m);
		cout << "e:" << e.get_vida() << endl;
		cout << "p:" << p.get_vida() << endl;

	} while (!((p.get_vida() > 0 && e.get_vida() <= 0) || (p.get_vida() <= 0 && e.get_vida() > 0)));


}


