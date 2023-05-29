#include "Tablice.hpp"
#include <iostream>
using namespace std;

int* f_stworz_tablice(int rozmiar)
{
	int* tab{nullptr};

	try
	{
		tab = new int[rozmiar]{};
	}
	catch (const std::bad_alloc& e)
	{
		cerr << "Blad przy tworzeniu tablicy" << endl;
		cin.ignore();
		exit(0);
	}

	return tab;
}

void f_usun_tablice(int* tab)
{
	delete[] tab;
}