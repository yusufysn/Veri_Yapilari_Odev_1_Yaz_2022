#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include "ArrayList.hpp"

class Factorial
{
private:
    int uzunluk;
    ArrayList *carpimSonuc;
    ArrayList *eldeler;
public:
    Factorial();
    void faktorielHesapla();
};

#endif