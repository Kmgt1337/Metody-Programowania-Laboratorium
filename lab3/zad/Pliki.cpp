#include "Pliki.hpp"
#include "Tablice.hpp"
#include <fstream>
#include <string>
#include <random>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int C_zestaw_danych::obecna_linia;

C_zestaw_danych::C_zestaw_danych(const char* sciezka)
{
    ifstream plik(sciezka);
    if(!plik.good())
    {
        exit(-1);
    }

    string linia;
    for(int i = 0; i < obecna_linia; i++)
    {
        std::getline(plik, linia);
    }

    int pom{};
    if(obecna_linia == 0)
    {
        plik >> pom;
    }

    plik >> rozmiar_zestawu_danych;
    zestaw_danych = f_stworz_tablice(rozmiar_zestawu_danych);
    int i = 0;
    while(plik >> pom)
    {
        if(i == rozmiar_zestawu_danych)
        {
            break;
        }
        zestaw_danych[i] = pom;
        i++;
    }

    rozmiar_zestawu_zapytan = pom;
    zestaw_zapytan = f_stworz_tablice(rozmiar_zestawu_zapytan);
    i = 0;
    while(plik >> zestaw_zapytan[i])
    {
        if(i == rozmiar_zestawu_zapytan)
        {
            break;
        }
        i++;
    }

    if(obecna_linia == 0)
    {
        obecna_linia += 5;
    }
    else
    {
        obecna_linia += 4;
    }
    plik.close();
}

C_zestaw_danych::~C_zestaw_danych()
{
    delete[] zestaw_danych;
    delete[] zestaw_zapytan;
}

int f_wczytaj_ilosc_zestawow_danych(const char* sciezka)
{
    ifstream plik(sciezka);
    if(!plik.good())
    {
        exit(-1);
    }

	int ilosc{};

    plik >> ilosc;
    plik.close();
    return ilosc;
}

bool f_zapisz_do_pliku_pierwszy_wynik(const char* sciezka, long long* I, long long* J, int rozmiar)
{
    ofstream plik(sciezka, ios::app);
    if(!plik.good())
    {
        exit(-1);
    }

    for(int i = 0; i < rozmiar; i++)
    {
        plik << "(" << I[i] << " " << J[i] << ") ";
    }
    plik.close();
    return true;
}

bool f_zapisz_do_pliku_drugi_wynik(const char* sciezka, long long* tab, int rozmiar)
{
    ofstream plik(sciezka, ios::app);
    if(!plik.good())
    {
        exit(-1);
    }

    plik << endl;
    for(int i = 0; i < rozmiar; i++)
    {
        if(i == 199)
        {
            break;
        }

        plik << tab[i] << " ";

        if(i % 49 == 0 && i != 0)
        {
            plik << endl;
        }
    }

    plik << endl;
    plik.close();
    return true;
}

bool f_stworz_plik_z_losowymi_danymi()
{
    ofstream plik("in/dane_losowe.txt", ios::trunc);
    if(!plik.good())
    {
        exit(-1);
    }

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<long long> dist(-100, 100);

    vector<long long> tab;
    for(int i = 0; i < 1000; i++)
    {
        tab.push_back(dist(mt));
    }

    sort(tab.begin(), tab.end());

    plik << 1 << endl;
    plik << 1000 << endl;
    for(int i = 0; i < 1000; i++)
    {
        plik << tab[i] << " ";
    }
    plik << endl;
    plik << 100 << endl;
    for(int i = 0; i < 100; i++)
    {
        plik << dist(mt) << " ";
    }
    plik.close();
    return true;
}