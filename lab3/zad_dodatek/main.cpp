#include "Pliki.hpp"
#include "Algorytm.hpp"
#include "Liczby.hpp"
#include <iostream>
using namespace std;

int main()
{
    int wybor{};
    cout << "Ktora opcje chcesz wykonac?"
        << "\n1. wszystkie podzbiory zbioru n-elementowego"
        << "\n2. k-elementowe podzbiory zbioru n-elementowego"
        << "\n3. wszystkie podzialy liczby n"
        << "\nPodaj wybor: ";
    cin >> wybor;

    switch(wybor)
    {
        case 1:
        {
            int n = f_wczytaj_liczbe_dodatnia();
            f_znajdz_wszystkie_podzbiory(n, "wynik_zad1.txt");
            break;
        }
        case 2:
        {
            int n = f_wczytaj_liczbe_dodatnia();
            int k = f_wczytaj_liczbe_dodatnia_mniejsza_od_zadanej(n);
            f_znajdz_wszystkie_kelementowe_podzbiory(n, k, "wynik_zad2.txt");
            break;
        }

        case 3:
        {
            int n = f_wczytaj_liczbe_dodatnia();
            f_znajdz_podzialy_liczby(n, "wynik_zad3.txt");
            break;
        }
    }
}