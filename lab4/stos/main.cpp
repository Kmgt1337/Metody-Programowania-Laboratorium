#include "Stos_tabl.hpp"
#include "Stos_lista.hpp"
#include "Plik.hpp"
#include "Test.hpp"
#include <stack>
#include <iostream>

int main()
{
    Stos_tbl<int> stos_tbl;
    Stos_lista<int> stos_lista;
    std::stack<int> stos_std;

    std::string sciezka;
    std::cin >> sciezka;

    f_wczytaj_z_pliku_stos_tabl(sciezka.c_str(), stos_tbl);
    f_wczytaj_z_pliku_stos_lista(sciezka.c_str(), stos_lista);
    f_wczytaj_z_pliku_stos_std(sciezka.c_str(), stos_std);

    f_testuj_stosy(stos_tbl, stos_lista, stos_std);
}