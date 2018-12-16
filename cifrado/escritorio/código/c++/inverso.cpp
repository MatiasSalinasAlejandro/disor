#include "inverso.hpp"

Inverso::Inverso(string entrada)
{
    this->texto=entrada;
}

string Inverso::invertir()
{
    string *copia=new string(texto);
    int tamanio=copia->size();
    string *nuevo=new string();


    for(int i = tamanio-1; i>= 0; i--)
    {
        nuevo+=copia->at(i);
    }

    return *nuevo;
}


string Inverso::cifrar(){
    return invertir();
}

string Inverso::decifrar(){
    return invertir();
}
