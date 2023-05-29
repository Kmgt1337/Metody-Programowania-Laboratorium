#include "Tablice.hpp"
#include <iostream>
using namespace std;

long long* f_stworz_tablice(int rozmiar)
{
	long long* tab{nullptr};

	try
	{
		tab = new long long[rozmiar];
	}
	catch (const std::bad_alloc& e)
	{
		cerr << "Blad przy tworzeniu tablicy" << endl;
		cin.ignore();
		exit(0);
	}

	return tab;
}

void f_usun_tablice(long long* tab)
{
	delete[] tab;
}