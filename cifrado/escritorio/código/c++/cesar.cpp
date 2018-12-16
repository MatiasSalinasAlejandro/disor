#include "cesar.hpp"

Cesar::Cesar(string orignal,int posicion)
{
    this->texto=orignal;
    this->semilla=posicion;
}

string Cesar::cifrar(){
    string textoCifrado;
    int i,movimiento;
    size_t pos;
    for(i=0;i<texto.length();i++){
        if(texto.at(i)>96 && texto.at(i)<123)
            texto.at(i) -= 32;
        //Paso las letras minusculas a mayusculas

        if(texto.at(i)<64 && texto.at(i)>91)
            textoCifrado+=texto.at(i);
        //Si el caracter actual no es una letra se
        //deja sin cifrar

        else{
            pos = letras.find(texto.at(i));
            if(((int)pos+semilla) > letras.length())
            movimiento = ((int)pos+semilla)-letras.length();
            else
            movimiento = (int)pos+semilla;
            //Revision para evitar que el valor quede
            //fuera de rango

            textoCifrado.append(letras,movimiento,1);
        }
    }
    return textoCifrado;
}

string Cesar::decifrar(){
    string textoNormal;
    int i,movimiento;
    size_t pos;
    for(i=0;i<texto.length();i++){
        if(texto.at(i)>96 && texto.at(i)<123)
            texto.at(i) -= 32;
        //Paso las letras minusculas a mayusculas

        if(texto.at(i)<64 && texto.at(i)>91)
            textoNormal+=texto.at(i);
        //Si el caracter actual no es una letra se
        //deja sin cifrar

        else{
            pos = letras.find(texto.at(i));
            if(((int)pos-semilla) < 0)
                movimiento = letras.length()+((int)pos-semilla);
            else
                movimiento = (int)pos-semilla;
            //Revision para evitar que el valor quede
            //fuera de rango, como la resta general un
            //valor negativo lo sumo al tamaño del
            //alfabeto para que avanze hacia atras

            textoNormal.append(letras,movimiento,1);
        }
    }
    return textoNormal;
}



