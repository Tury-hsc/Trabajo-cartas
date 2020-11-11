#include "Estadisticas.h"
#include <iostream>
using namespace std;
int   Estadisticas::get_atk() { return _atk; }
char* Estadisticas::get_nombre()
{
	return _nombre;
}
void Estadisticas::modificar_vida(int x)
{
	if (get_vida()+ x <=50) {
		_vida += x;
	}	
}
bool Estadisticas::get_pierdeturno()
{
	return _pierdeturno;
}
 int  Estadisticas::get_iniciativa() { return __inciativa;};
 int  Estadisticas::get_def() { return _def; };
 void Estadisticas::set_vida(int x)
 {
	 _vida = x;
 }
 void  Estadisticas::set_nombre(char* c)
{
	strcpy_s(_nombre, c);
}
void  Estadisticas::set_iniciativa(int x)
{
	__inciativa = x;
}
void  Estadisticas::set_def(int x)
{
	_def = x;
}
void  Estadisticas::set_atk(int x)
{
	_atk = x;
}
void  Estadisticas::set_pierdeturno(bool x)
{
	_pierdeturno = x;
}
 int  Estadisticas::get_vida() { return _vida; };
