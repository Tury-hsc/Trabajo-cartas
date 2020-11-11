#include "Mazo.h"
#include <time.h>
#include <iostream>



Mazo::Mazo()
{
    cargar_mano();
}

void Mazo::size_mazo()
{
    cout << Mano.size();
}

void Mazo::cargar_mano()
{
    FILE* p;
    Carta a;

    p = fopen("Carta.Mazo","rb");
    if (p==NULL)
    {
        cout << "Error al Cargar el Archivo de Mazo" << endl;
        return;
    }
    while (fread(&a,sizeof(Carta),1,p)==1)
    {
        Mano.push_back(a);
    }
    fclose(p);
}

int Mazo::get_cantidad()
{
    return _cantidad;
}

int Mazo::cantida_de_cartas()
{
    FILE* p;
    Carta a;
    int x=0;
    p=fopen("Carta.Mazo", "rb");

    while (fread(&a,sizeof(Carta),1,p)==1)
    {
        x++;
      
    }

    cout << x;
   
    fclose(p);
    return  x;
}

void Mazo::set_cantidad()
{
    Mazo a;
    _cantidad = a.cantida_de_cartas();
   
}

void Mazo::set_mano()
{
    srand(time(NULL));
    int x;
    Mazo a;
    a.cargar_mano();
    for (auto &var : _mano)
    {   
        x = a.Mano.size();
        //cout << x;
        x = rand() % x;
        //cout << x;
        var = a.Mano[x];

    }
   
   

}

char * Mazo::nombre_carta(Mazo &a,int x)
{
   
    return a._mano[x].get_nombre();
   



}

Carta Mazo::get_mano(int x)
{
    return _mano[x];
}

void Mazo::cambiar(int x)
{
    int c=4;
    srand(time(NULL));
    c  = rand() % c+1;
    _mano[x] = Mano[c];

}

