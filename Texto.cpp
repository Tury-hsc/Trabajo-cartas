#include "Texto.h"
#include<iostream>

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

void Texto::mostrarTexto() {
	Texto a;
	char texto_nuevo[300];
	int pos = 0;

	while (a.leerDeDisco(pos) == true) {
		strcpy(texto_nuevo, a.getTexto());
		std::cout << texto_nuevo;
		pos++;
	}

	system("pause");
}

