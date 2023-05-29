// MP2023, Kamil Gawlik
// zadanie startowe

#include <iostream>
#include <limits>
using namespace std;

// funkcja, ktora tworzy dynamiczna tablice jedynowymiarowa
int* f_stworz_tablice(int rozmiar)
{
	int* tab{nullptr};

	try
	{
		tab = new int[rozmiar];
	}
	catch (const std::bad_alloc& e)
	{
		cerr << "Blad przy tworzeniu tablicy" << endl;
		cin.ignore();
		exit(0);
	}

	return tab;
}

// funkcja, ktora usuwa przyslana jej tablice
void f_usun_tablice(int* tab)
{
	delete[] tab;
}

// funkcja do wczytania jednej liczby typu z zadanego przedzialu
template <typename T>
T f_wczytaj_liczbe(T przedzial_min = numeric_limits<T>::min(), T przedzial_max = numeric_limits<T>::max())
{
	T liczba;
	cin >> liczba;

	while (liczba < przedzial_min || liczba > przedzial_max)
	{
		cout << "!";
		cin >> liczba;
	}

	return liczba;
}

// funkcja do zapelnienia tablicy liczbami wprowadzanymi z klawiatury
void f_zapelnij_tablice(int* tab, int rozmiar)
{
	for(int i = 0; i < rozmiar; i++)
	{
		tab[i] = f_wczytaj_liczbe(-2000, 2000);
	}
}

// pomocnicza klasa do przechowywania wyniku dzialania algorytmu z zadania
struct C_wynik
{
	unsigned int skad{};
	unsigned int dokad{};
	int suma{};
};

// funkcja do wyswietlenia wynikow dzialania algorytmu
void f_wyswietl_wyniki(C_wynik wynik)
{
	cout << wynik.skad << " " << wynik.dokad << " " << wynik.suma << endl;
}

// algorytm z zadania
C_wynik f_algorytm(int* tab, int rozmiar)
{
	int obecna_suma{};
    int najlepsza_suma{};
    unsigned int skad{};
    unsigned int dokad{};

    for(int i = 0; i < rozmiar; i++)
    {
		if(obecna_suma < 0)
        {
            skad = i;
            obecna_suma = 0;
        }

        if(tab[i] > 0)
        {
            obecna_suma += 3 * tab[i];
        }
        else
        {
            obecna_suma += 2 * tab[i];
        }

        if(obecna_suma > najlepsza_suma)
        {
            najlepsza_suma = obecna_suma;
            dokad = i;
        }
    }

	if(najlepsza_suma == 0)
	{
		dokad = 0;
		skad = 0;
	}

	return C_wynik{skad, dokad, najlepsza_suma};
}

// funkcja main() od ktorej rozpoczyna sie wykonywanie programu
int main()
{
	int liczba_zestawow{};
	unsigned int rozmiar_tablicy{};
	C_wynik wyniki;
	int* elemety{nullptr};

	liczba_zestawow = f_wczytaj_liczbe(1);

	for (int j = 0; j < liczba_zestawow; j++)
	{
		rozmiar_tablicy = f_wczytaj_liczbe(1, 1000000);
		elemety = f_stworz_tablice(rozmiar_tablicy);

		f_zapelnij_tablice(elemety, rozmiar_tablicy);

		wyniki = f_algorytm(elemety, rozmiar_tablicy);
		f_wyswietl_wyniki(wyniki);

		f_usun_tablice(elemety);
	}

	return 0;
}