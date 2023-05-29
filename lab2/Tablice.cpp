#include "Tablice.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double* f_stworz_tablice(int rozmiar)
{
	double* tab{nullptr};

	try
	{
		tab = new double[rozmiar];
	}
	catch (const std::bad_alloc& e)
	{
		cerr << "Blad przy tworzeniu tablicy" << endl;
		cin.ignore();
		exit(0);
	}

	return tab;
}

void f_usun_tablice(double* tab)
{
	delete[] tab;
}

double** f_stworz_tablice_2D(int wiersze, int kolumny)
{
	double** tab{ nullptr };

	try
	{
		tab = new double* [wiersze];
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "\nBlad przy tworzeniu tablicy" << endl;
		cin.ignore();
		exit(0);
	}

	for (int i = 0; i < wiersze; i++)
	{
		try
		{
			tab[i] = new double[kolumny];
		}
		catch (const std::exception& e)
		{
			std::cerr << "\nBlad przy tworzeniu tablicy" << endl;
			cin.ignore();
			exit(0);
		}
	}

	return tab;
}

void f_usun_tablice_2D(double** tab, int wiersze)
{
    for(int i = 0; i < wiersze; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
}
