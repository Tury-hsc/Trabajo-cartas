#include "Texto.h"
#include<iostream>

char* Texto::getTexto() {

	return texto;
}

void Texto::setTexto() {
	FILE* p;

	std::cout << "Ingrese Texto"<<std::endl; std::cin.getline(texto, 300, '\n');

	p = fopen("texto_npc.txt", "ab");
	if (p == NULL) std::cout << "error" << std::endl;

	fwrite(this, sizeof(*this), 1, p);
	std::cout << "Exito";

	fclose(p);
}

bool Texto::leerDeDisco(int pos)
{
	bool leyo;
	FILE* p;
	p = fopen("texto_npc.txt", "rb");
	if (p == NULL)
		return false;
	fseek(p, sizeof(*this) * pos, 0);
	leyo = fread(this, sizeof * this, 1, p);
	fclose(p);
	return leyo;
}

char* Texto::obtenerTexto(int pos) {
	Texto a;

	if (a.leerDeDisco(pos) == true) {
		//std::cout<<a.getTexto()<<std::endl;
		return a.getTexto();
	}

}

