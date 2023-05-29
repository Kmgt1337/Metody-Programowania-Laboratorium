#include "Pliki.hpp"
#include <fstream>
#include <iostream>
using namespace std;

bool f_wyczysc_plik(const char* sciezka)
{
    ofstream plik(sciezka, ios::trunc);
    if(!plik)
    {
        exit(-1);
    }
    plik.close();
    return true;
}

bool f_pisz_do_pliku(const char* sciezka, int* B, int rozmiar)
{
    ofstream plik(sciezka, ios::app);
    if(!plik)
    {
        exit(-1);
    }

    for(int i = 1; i <= rozmiar; i++)
    {
        plik << B[i];
    }
    plik << endl;

    plik.close();
    return true;
}

bool f_pisz_do_pliku_podzialy(const char* sciezka, int* S, int* R, int rozmiar)
{
    ofstream plik(sciezka, ios::app);
    if(!plik)
    {
        exit(-1);
    }

    for(int i = 1; i <= rozmiar; i++)
    {
        for(int j = 0; j < R[i]; j++)
        {
            plik << S[i] << " ";
        }
    }
    plik << endl;

    plik.close();
    return true;
}