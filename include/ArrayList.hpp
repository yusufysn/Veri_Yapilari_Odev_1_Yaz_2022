#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
class ArrayList
{
private:
    short* items;
    int length;
    int capacity;
    void reserve(int newCapacity);              // dizinin kapasitesini iki katina çikariyor.
public:
    
    ArrayList();
    int size()const;                            // dizinin uzunlugunu veriyor.
    short getElement(int index);                // girilen indexdeki sayiyi veriyor.
    void insert(int index,const short item);    // istenen indexe sayi ekliyor.
    void add(const short item);                 // istenen indexe sayi ekliyor.
    void removeAt(int index);                   // girilen indexdeki sayiyi siliyor.
    void changeElement(int index, short item);  //sayiyi girilen indexe atiyor.
    void clear();                               // listeyi sifirliyor.
    ~ArrayList();
};



#endif 