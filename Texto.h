#pragma once
class Texto
{

private:
	char texto[300];

public:

	void setTexto();
	char* obtenerTexto(int pos);
	bool leerDeDisco(int pos);
	char* getTexto();
};

