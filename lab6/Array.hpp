#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

/*
* Funkcja tworzaca jednowymiarowa dynamiczna tablice
* @param rozmiar rozmiar tablicy
* @returns wskaznik do utworzonej tablicy
*/
template <typename T>
T* f_create_array(int rozmiar)
{
	int* tab{nullptr};

	try
	{
		tab = new T[rozmiar]{};
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
* Funkcja usuwajaca jednowymiarowa dynamiczna tablice
* @param tab wskaznik do tablicy
*/
template <typename T>
void f_delete_array(T* tab)
{
	delete[] tab;
}

/*
* Funkcja tworzaca dwuwymiarowa dynamiczna tablice
* @param wiersze liczba wierszy
* @param kolumny liczba kolumn
* @returns wskaznik do utworzonej tablicy
*/
template <typename T>
T** f_create_2d_array(int wiersze, int kolumny)
{
    T** tab{nullptr};

    try
    {
        tab = new T*[wiersze]{};
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "\nBlad przy tworzeniu tablicy" << std::endl;
        std::cin.ignore();
        exit(0);
    }

    for(int i = 0; i < wiersze; i++)
    {
        try
        {
            tab[i] = new T[kolumny]{};
        }
        catch(const std::exception& e)
        {
            std::cerr << "\nBlad przy tworzeniu tablicy" << std::endl;
            std::cin.ignore();
            exit(0);
        }
    }

    return tab; 
}


/*
* Funkcja usuwajaca dwuwymiarowa dynamiczna tablice
* @param tab wskaznik do tablicy
* @param wiersze liczba wierszy
*/
template <typename T>
void f_delete_2d_array(T** tab, int wiersze)
{
    for(int i = 0; i < wiersze; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
}

#endif