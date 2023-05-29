// MP2023, Kamil Gawlik
// zadanie 1.

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

// funkcja, ktora tworzy dynamiczna tablice 2D
int** f_stworz_tablice_2D(int wiersze, int kolumny)
{
    int** tab{nullptr};

    try
    {
        tab = new int*[wiersze];
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "\nBlad przy tworzeniu tablicy" << endl;
        cin.ignore();
        exit(0);
    }

    for(int i = 0; i < wiersze; i++)
    {
        try
        {
            tab[i] = new int[kolumny];
        }
        catch(const std::exception& e)
        {
            std::cerr << "\nBlad przy tworzeniu tablicy" << endl;
            cin.ignore();
            exit(0);
        }
    }

    return tab; 
}

// funkcja, ktora usuwa przysylana jej tablice 2D
void f_usun_tablice_2D(int** tab, int wiersze)
{
    for(int i = 0; i < wiersze; i++)
    {
        delete[] tab[i];
    }
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

// funkcja, ktora wczytuje z klawiatury rozmiar tablicy 2D (liczbe wierszy i kolumn)
void f_wczytaj_rozmiar_tablicy_2D(int& wiersze, int& kolumny, int przedzial_min = 0, int przedzial_max = numeric_limits<int>::max())
{
    cin >> wiersze >> kolumny;

    while ((wiersze < przedzial_min || kolumny < przedzial_min) || 
        (wiersze > przedzial_max || kolumny > przedzial_max))
	{
		cout << "!";
		cin >> wiersze >> kolumny;
	}
}

// funkcja, ktora zapelnia tablice 2D danymi wprowadzanymi z klawiatury
void f_zapelnij_tablice_2D(int** tab, int wiersze, int kolumny)
{
    for(int i = 0; i < wiersze; i++)
    {
        for(int j = 0; j < kolumny; j++)
        {
            tab[i][j] = f_wczytaj_liczbe(-32768, 32768);
        }
    }
}

// algorytm Kadane do znajdywania sumy maksymalnej ciaglej podtablicy
int kadane(int* tab, int rozmiar)
{
    int obecna_suma{};
    int najlepsza_suma{};

    for(int i = 0; i < rozmiar; i++)
    {
        obecna_suma += tab[i];
        
        if(obecna_suma > najlepsza_suma)
        {
            najlepsza_suma = obecna_suma;
        }

        if(obecna_suma < 0)
        {
            obecna_suma = 0;
        }
    }

    return najlepsza_suma;
}

// algorytm z zadania
int f_algorytm(int** tab, int wiersze, int kolumny)
{
    int* temp = f_stworz_tablice(wiersze);
    int najwieksza_suma{};
    int suma_kadane{};

    for(int lewo = 0; lewo < kolumny; lewo++)
    {
        for(int i = 0; i < wiersze; i++)
        {
            temp[i] = 0;
        }

        for(int prawo = lewo; prawo < kolumny; prawo++)
        {
            for(int i = 0; i < wiersze; i++)
            {
                temp[i] += tab[i][prawo];
            }

           suma_kadane = kadane(temp, wiersze);
           if(suma_kadane > najwieksza_suma)
           {
                najwieksza_suma = suma_kadane;  
           }   
        }
    }

    f_usun_tablice(temp);
    return najwieksza_suma;
}

// funkcja main
int main()
{
    int liczba_zestawow{};
    int wiersze{};
    int kolumny{};
    int** elementy{nullptr};
    int wynik{};

    liczba_zestawow = f_wczytaj_liczbe(1);
    for(int i = 0; i < liczba_zestawow; i++)
    {
        f_wczytaj_rozmiar_tablicy_2D(wiersze, kolumny, 1, 100);
        elementy = f_stworz_tablice_2D(wiersze, kolumny);
        f_zapelnij_tablice_2D(elementy, wiersze, kolumny);
        wynik = f_algorytm(elementy, wiersze, kolumny);

        cout << wynik << endl;

        f_usun_tablice_2D(elementy, wiersze);
    }
}

