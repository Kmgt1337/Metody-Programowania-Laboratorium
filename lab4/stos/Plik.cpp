#include "Plik.hpp"
#include <fstream>
#include <iostream>
using namespace std;

bool f_wczytaj_z_pliku_stos_tabl(const char* sciezka, Stos_tbl<int>& stos)
{
    ifstream plik(sciezka);
    if(!plik.good())
    {
        exit(-1);
    }

    int temp;
    plik >> temp;
    while(plik >> temp)
    {
        stos.dodaj(temp);
    }

    plik.close();
    return true;
}

bool f_wczytaj_z_pliku_stos_lista(const char* sciezka, Stos_lista<int>& stos)
{
   ifstream plik(sciezka);
    if(!plik.good())
    {
        exit(-1);
    }

    int temp;
    plik >> temp;
    while(plik >> temp)
    {
        stos.dodaj(temp);
    }

    plik.close();
    return true; 
}

bool f_wczytaj_z_pliku_stos_std(const char* sciezka, std::stack<int>& stos)
{
    ifstream plik(sciezka);
    if(!plik.good())
    {
        exit(-1);
    }

    int temp;
    plik >> temp;
    while(plik >> temp)
    {
        stos.push(temp);
    }

    plik.close();
    return true;
}