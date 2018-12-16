#ifndef CESAR_HPP
#define CESAR_HPP


#include <string>
using namespace std;

class Cesar
{
private:
    string letras = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    string texto;
    int semilla;
public:
    Cesar(string,int);
    string cifrar();
    string decifrar();
};

#endif // CESAR_HPP
