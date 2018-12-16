#ifndef INVERSO_HPP
#define INVERSO_HPP

#include<string>
using namespace std;


class Inverso
{
private:
    string texto;
    string invertir();
public:
    Inverso(string);
    string cifrar();
    string decifrar();

};

#endif // INVERSO_HPP
