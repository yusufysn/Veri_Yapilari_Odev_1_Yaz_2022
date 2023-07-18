/** 
* @file        : main.cpp
* @description : Odevde istenildigi gibi faktoriyel hesabi yapiyor.
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 1. Odev
* @date        : 23.07.2022
* @author      : Yusuf Yesin
*/
#include "ArrayList.hpp"
#include "Factorial.hpp"
#include<iostream>

using namespace std;

int main()
{
    Factorial *f = new Factorial();
    f->faktorielHesapla();
    delete f;
    return 0;
}