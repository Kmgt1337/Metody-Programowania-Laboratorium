#include "Pliki.hpp"
#include "Tablice.hpp"
#include "Wizualizacja.hpp"
#include "Algorytm.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int ktory{};

	cout << "podaj sciezke siatek silnika: ";
	string sciezka_silnik;
	cin >> sciezka_silnik;

	ktory = f_okresl_ktory_silnik(sciezka_silnik);

	cout << "podaj sciezka siatek nieznanego silnika: ";
	string sciezka_nieznany;
	cin >> sciezka_nieznany;

	C_wiersze_kolumny rozmiary = f_odczytaj_liczbe_wierszy_i_kolumn_z_pliku(sciezka_silnik.c_str());
	C_wiersze_kolumny rozmiary_nieznanego = f_odczytaj_liczbe_wierszy_i_kolumn_z_pliku(sciezka_nieznany.c_str());

	double** silnik_siatki = f_odczytaj_dane_z_pliku(sciezka_silnik.c_str(), rozmiary.wiersze, rozmiary.kolumny);
	double** nieznany_siatki = f_odczytaj_dane_z_pliku(sciezka_nieznany.c_str(), rozmiary_nieznanego.wiersze, rozmiary_nieznanego.kolumny);

	double* bledy_mse = f_stworz_tablice(rozmiary.wiersze / 2);
	C_wynik_algorytmu wynik = f_wyznacz_minimalny_blad_mse(silnik_siatki, rozmiary.wiersze, rozmiary.kolumny, nieznany_siatki, bledy_mse);

	if(!f_zapisz_wyniki(sciezka_nieznany.c_str(), wynik, bledy_mse, silnik_siatki, rozmiary.wiersze, rozmiary.kolumny))
	{
		return -1;
	}
	cout << "Zapisano wyniki do pliku" << endl;

	if(argc > 0)
	{
		Wizualizacja w1(argv[0], silnik_siatki, wynik.indeks, nieznany_siatki, rozmiary.wiersze, rozmiary.kolumny, ktory);
		w1.uruchom_skrypt();
	}

	f_usun_tablice(bledy_mse);
	f_usun_tablice_2D(silnik_siatki, rozmiary.wiersze);
	f_usun_tablice_2D(nieznany_siatki, rozmiary_nieznanego.wiersze);

	cin.get();
}