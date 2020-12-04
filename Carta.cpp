#include "Carta.h"
#include <iostream>
using namespace std;
void Carta::set_nombre(char* c) { strcpy_s(_nombre, c); };
void Carta::set_afectaPersonaje(bool x) { _afectaPersonaje = x; }
void Carta::set_stun(bool x)
{
	_stun = x;
};
void Carta::set_valor(int x) { _valor = x; };
bool Carta::get_afectaPersonaje() { return _afectaPersonaje; };
int  Carta::get_valor() { return _valor; };
char* Carta::get_nombre() {
	return _nombre;
 }

void Carta::crear_carta()
{	
	FILE* p;
	Carta a;
	char nombre[20];
	int valor;
	bool stun,pj;

	cout << "nombre" << endl;
	cin >> nombre;
	a.set_nombre(nombre);

	cout << "valor" << endl;
	cin >> valor;
	a.set_valor(valor);

	cout << "es stun 1 si , 0 no" << endl;
	cin >> stun;
	a.set_stun(stun);

	cout << "Afecta a Personaje 1 si , 0 no" << endl;
	cin >> pj;
	a.set_afectaPersonaje(pj);

	p = fopen("Carta.Mazo", "ab");
	if (p == NULL) cout << "error" << endl;

	fwrite(&a, sizeof(a),1, p);
	cout << "Exito";

	fclose(p);

}

bool Carta::get_stun()
{
	return _stun;
}




