#pragma once
class Texto
{

private:
	char texto[300];

public:

	void setTexto();
	void mostrarTexto();
	bool leerDeDisco(int pos);
	char* getTexto() { return texto; }
};

