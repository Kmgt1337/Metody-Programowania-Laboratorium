#ifndef TABLICA_HPP
#define TABLICA_HPP
#include <stdexcept>
#include <iostream>

/*
* Funkcja szablonowa tworzaca jednowymiarowa tablice dynamiczna
* @param rozmiar rozmair tablicy
* @returns wskaznik do utworzonej tablicy 
*/
template<typename T>
T* f_stworz_tablice_jednowymiarowa(int rozmiar)
{
    T* tab{nullptr};

	try
	{
		tab = new T[rozmiar];
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Blad przy tworzeniu tablicy" << std::endl;
		std::cin.ignore();
		exit(0);
	}

	return tab;
}

/*
* Funkcja szablonowa usuwajaca jednowymiarowa tablice dynamiczna
* @param tab wskaznik do tablicy
*/
template<typename T>
void f_usun_tablice_jednowymiarowa(T* tab)
{
    delete[] tab;
}

#endif