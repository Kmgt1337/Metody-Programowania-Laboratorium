#include "Test.hpp"
#include <fstream>
#include <iomanip>
using namespace std;

void f_testuj_stosy(Stos_tbl<int>& stos_tabl, Stos_lista<int>& stos_lista, std::stack<int>& stos_std)
{
    ofstream plik("out.txt");
    if(!plik.good())
    {
        exit(-1);
    }

    plik << "stos size() \t stos_tbl = " << stos_tabl.rozmiar() <<  "\t stos_lista = " << stos_lista.rozmiar() <<  "\tstos_std = " << stos_std.size() << endl;

    plik << endl;
    plik << "stos_tbl: ";
    while(!stos_tabl.czy_jest_pusty())
    {
        plik << stos_tabl.element_szczytowy() << " ";
        stos_tabl.usun();
    }

    plik << endl << endl;
    plik << "stos_lista: ";
    while(!stos_lista.czy_jest_pusty())
    {
        plik << stos_lista.element_szczytowy() << " ";
        stos_lista.usun();
    }

    plik << endl << endl;
    plik << "stos_std: ";
    while(!stos_std.empty())
    {
        plik << stos_std.top() << " ";
        stos_std.pop();
    }

    plik << endl << endl;
    plik << "for(int i = 100; i < 120; i++) push(i);";
    plik << endl;

    for(int i = 100; i < 120; i++)
    {
        stos_tabl.dodaj(i);
        stos_lista.dodaj(i);
        stos_std.push(i);
    }
    
    plik << endl;
    plik << "stos_tbl: ";
    while(!stos_tabl.czy_jest_pusty())
    {
        plik << stos_tabl.element_szczytowy() << " ";
        stos_tabl.usun();
    }

    plik << endl << endl;
    plik << "stos_lista: ";
    while(!stos_lista.czy_jest_pusty())
    {
        plik << stos_lista.element_szczytowy() << " ";
        stos_lista.usun();
    }

    plik << endl << endl;
    plik << "stos_std: ";
    while(!stos_std.empty())
    {
        plik << stos_std.top() << " ";
        stos_std.pop();
    }

    plik.close();
}