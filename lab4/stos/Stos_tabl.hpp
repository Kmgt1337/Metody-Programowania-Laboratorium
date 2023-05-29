#ifndef STOS_TABL_HPP
#define STOS_TABL_HPP

#include <stdexcept>
#include "Tablica.hpp"

// Szablon stosu opartego na tablicy dynamicznej 
template<typename T>
class Stos_tbl
{
private:
    // wskaznik do tablicy dynamicznej
    T* _pojemnik;
    
    // pojemnosc stosu
    int _pojemnosc;

    // obecna ilosc elementow na stosie
    int _n;

    /*
    * Funkcja skladowa zmieniajca rozmiar tablicy dynamicznej
    * @param pojemnosc nowy rozmiar tablicy
    */
    void zmien_rozmiar(int pojemnosc);

public:
    // Konstruktor 
    Stos_tbl();

    // Destruktor
    ~Stos_tbl();

    /*
    * Funkcja skladowa dodajaca na wierzcholek stosu nowy element
    * @param elem element do dodania
    */
    void dodaj(T elem);

    // Funkcja skladowa usuwajaca z wierzcholku stosu jeden element
    void usun();

    /*
    * Funkcja skladowa zwracajaca element szczytowy stosu
    * @returns element szczytowy stosu
    */
    T element_szczytowy();

    /*
    * Funkcja skladowa sprawdzajaca czy stos jest pusty
    * @returns true jesli stos jest pusty, false jesli posiada elementy
    */
    bool czy_jest_pusty();

    /*
    * Funkcja zwracajaca rozmiar stosu
    * @returns rozmiar stosu
    */
    int rozmiar();
};

template<typename T>
Stos_tbl<T>::Stos_tbl()
{
    _n = 0;
    _pojemnosc = 1;
    _pojemnik = f_stworz_tablice_jednowymiarowa<T>(_pojemnosc);
}

template<typename T>
Stos_tbl<T>::~Stos_tbl()
{
    f_usun_tablice_jednowymiarowa<T>(_pojemnik);
}

template<typename T>
void Stos_tbl<T>::zmien_rozmiar(int pojemnosc)
{
    T* temp = f_stworz_tablice_jednowymiarowa<T>(pojemnosc);
    for(int i = 0; i < _n; i++)
    {
        temp[i] = _pojemnik[i];
    }
    f_usun_tablice_jednowymiarowa<T>(_pojemnik);
    _pojemnik = temp;
    _pojemnosc = pojemnosc;
}

template<typename T> 
void Stos_tbl<T>::dodaj(T elem)
{
    if(_n == _pojemnosc)
    {
        zmien_rozmiar(_pojemnosc * 2);
    }
    _pojemnik[_n] = elem;
    _n++;
}

template<typename T>
void Stos_tbl<T>::usun()
{
    if(_n == 0)
    {
        throw std::underflow_error("underflow error");
    }

    --_n;
    if (_n == _pojemnosc / 4)
	{
		zmien_rozmiar(_pojemnosc / 2);
	}
}

template<typename T>
T Stos_tbl<T>::element_szczytowy()
{
    return _pojemnik[_n - 1];
}

template<typename T>
bool Stos_tbl<T>::czy_jest_pusty()
{
    return rozmiar() == 0;
}

template<typename T>
int Stos_tbl<T>::rozmiar()
{
    return _n;
}

#endif