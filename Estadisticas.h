#pragma once
class Estadisticas
{
private:
	int _vida, __inciativa, _def, _atk;
	char _nombre[20];
	bool _pierdeturno;

public:
	void set_vida(int x);
	void set_nombre(char* c);
	void set_iniciativa(int x);
	void set_def(int x);
	void set_atk(int x);
	void set_pierdeturno(bool x);
	int get_vida();
	int get_iniciativa();
	int get_def();
	int get_atk();
	char* get_nombre();
	void modificar_vida(int x);	
	bool get_pierdeturno();


};

