#include "Liczby.hpp"
#include <iostream>
using namespace std;

int f_wczytaj_liczbe_dodatnia()
{
    int liczba{};
    cin >> liczba;

    while(liczba <= 0)
    {
        cout << "!";
        cin >> liczba;
    }

    return liczba;
}

int f_wczytaj_liczbe_dodatnia_mniejsza_od_zadanej(int zadana)
{
    int liczba{};
    cin >> liczba;

    while(liczba <= 0 || liczba >= zadana)
    {
        cout << "!";
        cin >> liczba;
    }

    return liczba;
}