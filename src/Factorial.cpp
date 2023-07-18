/** 
* @file        : Factoial.cpp
* @description : Odevde istenildigi gibi faktoriyel hesabi yapiyor.
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 1. Odev
* @date        : 23.07.2022
* @author      : Yusuf Yesin
*/

#include "Factorial.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Factorial::Factorial()
{
    carpimSonuc = new ArrayList();
    eldeler     = new ArrayList();

    cout<<"Bir Sayi Girin: ";
    cin>>uzunluk;
    if(uzunluk<0) {cout<<"NEGATIF SAYI GIRILEMEZ !!!\n";}
}
void Factorial::faktorielHesapla()
{
    carpimSonuc->add(1);
    eldeler->add(0);

    int gecici, basamakToplami, elde1, elde2 = 0;
    int sayi=1;
    if(uzunluk>80000)
    cout<<"Bu islem 2 dakika surebilir...\n";
    for(int i = 0;i < uzunluk-1;i++) // 1 den baslayip girilen sayiya kadar devam ediyor.
    {
        sayi++;
        gecici = sayi;
        basamakToplami = 0;

        while (gecici >= 1) // carpilacak tum sayilarin basamaklarini topluyor.
        {
            basamakToplami += gecici%10;
            gecici/=10;
        }
        
        for(int j = 0;j < carpimSonuc->size();j++) //sonuc dizisindeki tum indisleri teker teker basamkToplami ile carpiyor.
        {
            gecici = carpimSonuc->getElement(j)*basamakToplami;
            carpimSonuc->changeElement(j,(gecici)%10);
            eldeler->changeElement(j,(gecici)/10);
            if(j+1 == carpimSonuc->size() && eldeler->getElement(j)!=0) {carpimSonuc->add(0); eldeler->add(0);} //son elemen ise ve elde 0 değilse sona 0 ekle
        }
        if (gecici/100 != 0) {eldeler->changeElement(carpimSonuc->size()-1,((gecici)/10)%10);eldeler->add(gecici/100); carpimSonuc->add(0);}
            
        elde1 = carpimSonuc->getElement(0);
        for(int j = 1;j < eldeler->size();j++) //sonuc dizisi ve eldeler dizisini toluyor ve toplami sonuca atıyor.
        {
            if(j+1 == carpimSonuc->size() && eldeler->getElement(j)!=0) {carpimSonuc->add(0); eldeler->add(0);}
            
            elde1 = carpimSonuc->getElement(j) + eldeler->getElement(j-1);
            carpimSonuc->changeElement(j,elde1%10 + elde2);
            elde2 = 0;
            
            if(j == carpimSonuc->size()-1 && (elde1>9)) {carpimSonuc->add(elde1/10); eldeler->add(0);break;}
            
            if(elde1/10 && j+1 != carpimSonuc->size()) elde2 = elde1/10;
        }
    }
    
    ofstream sonucYaz;
    sonucYaz.open("Sonuc.txt");
    for (int i = carpimSonuc->size()-1; i >= 0; i--) // sonucu Sonuc.txt dosyasina atiyor.
    {
        sonucYaz<<carpimSonuc->getElement(i);
    }
    sonucYaz.close();
    cout<<"Sonuc dosyaya yazdirildi.\n";

    delete carpimSonuc;
    delete eldeler;
}