#include "Pliki.hpp"
#include "Algorytm.hpp"
using namespace std;

bool f_zapisz_wyniki(const char* sciezka, C_wynik_algorytmu wynik, double* bledy_mse, double** siatki, unsigned int wiersze, unsigned int kolumny)
{
	string temp{sciezka};
	size_t indeks = temp.find(".txt");
	if (indeks != string::npos)
	{
		temp = temp.substr(0, indeks);
		temp += "_wyniki.txt";
	}
	ofstream uchwyt(temp);
	if (!uchwyt.good())
	{
		return false;
	}

	uchwyt << "Wartosci bledow mse dla kazdej z siatek: " << endl << endl;;
	for(unsigned int i = 0; i < wiersze / 2; i++)
	{
		uchwyt << bledy_mse[i] << " ";
	}

	uchwyt << endl << endl;;
	uchwyt << "Minimalny blad mse: " << wynik.najmniejszy_blad_mse << endl << endl;

	uchwyt << "Wektor Y, X z wszystkimi danymi najlepszego dopasowania:" << endl;

	for(unsigned int j = 0; j < kolumny; j++)
	{
		uchwyt << siatki[wynik.indeks][j] << " ";
	}

	uchwyt << endl;
	for(unsigned int j = 0; j < kolumny; j++)
	{
		uchwyt << siatki[wynik.indeks + 1][j] << " ";
	}

	uchwyt.close();
	return true;
}

C_wiersze_kolumny f_odczytaj_liczbe_wierszy_i_kolumn_z_pliku(const char* sciezka)
{
	ifstream uchwyt(sciezka);
	if (!uchwyt.good())
	{
		exit(-1);
	}

	string linia;
	unsigned int wiersze{};
	unsigned int kolumny{};
	double pom{};

	while (getline(uchwyt, linia))
	{
		if(wiersze == 0)
		{
			istringstream ss(linia);
			while (ss >> pom)
			{
				kolumny++;
			}
		}
		wiersze++;
	}

	return C_wiersze_kolumny{wiersze, kolumny};
}

double** f_odczytaj_dane_z_pliku(const char* sciezka, int wiersze, int kolumny)
{
	ifstream uchwyt(sciezka);
	if (!uchwyt.good())
	{
		exit(-1);
	}

	string linia;
	double pom;

	double** tab = f_stworz_tablice_2D(wiersze, kolumny);

	int i{}, j{};
	while (getline(uchwyt, linia))
	{
		j = 0;
		istringstream ss(linia);
		while (ss >> pom)
		{
			tab[i][j] = pom;
			j++;
		}
		i++;
	}

	return tab;
}