#include "Pliki.hpp"
#include "Algorytm.hpp"
#include "Tablice.hpp"
#include <iostream>
#include <string>

int main()
{   
    f_stworz_plik_z_losowymi_danymi();
    
    std::string wejscie, wyjscie;
    std::cin >> wejscie >> wyjscie;

    int ile = f_wczytaj_ilosc_zestawow_danych(wejscie.c_str());
    for(int i = 0; i < ile; i++)
    {
        C_zestaw_danych z(wejscie.c_str());
        long long* I = f_stworz_tablice(z.rozmiar_zestawu_zapytan);
        long long* J = f_stworz_tablice(z.rozmiar_zestawu_zapytan);

        for(int j = 0; j < z.rozmiar_zestawu_zapytan; j++)
        {   
            I[j] = f_zlicz_ile_elementow(z.zestaw_danych, z.rozmiar_zestawu_danych, z.zestaw_zapytan[j]);
            J[j] = f_wysz_interpolacyjne(z.zestaw_danych, z.rozmiar_zestawu_danych, z.zestaw_zapytan[j]);
        }
        f_zapisz_do_pliku_pierwszy_wynik(wyjscie.c_str(), I, J, z.rozmiar_zestawu_zapytan);

        int rozmiar_duplikatow = f_usun_duplikaty(z.zestaw_danych, z.rozmiar_zestawu_danych);
        f_zapisz_do_pliku_drugi_wynik(wyjscie.c_str(), z.zestaw_danych, rozmiar_duplikatow);

        f_usun_tablice(I);
        f_usun_tablice(J);
    }
}