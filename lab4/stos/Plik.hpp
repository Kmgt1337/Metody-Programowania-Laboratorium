#ifndef PLIK_HPP
#define PLIK_HPP

#include "Stos_tabl.hpp"
#include "Stos_lista.hpp"
#include <stack>

/*
* Funkcja wczytujaca z pliku dane do stosu opartego na tablicy dynamicznej
* @param sciezka sciezka do pliku
* @param stos stos
* @returns prawda jesli funkcja wykonala prace prawidlowo
*/
bool f_wczytaj_z_pliku_stos_tabl(const char* sciezka, Stos_tbl<int>& stos);

/*
* Funkcja wczytujaca z pliku dane do stosu opartego na liscie jednokierunkowej
* @param sciezka sciezka do pliku
* @param stos stos
* @returns prawda jesli funkcja wykonala prace prawidlowo
*/
bool f_wczytaj_z_pliku_stos_lista(const char* sciezka, Stos_lista<int>& stos);

/*
* Funkcja wczytujaca z pliku dane do stosu z standardowej implementacji stosu z std::Stack
* @param sciezka sciezka do pliku
* @param stos stos
* @returns prawda jesli funkcja wykonala prace prawidlowo
*/
bool f_wczytaj_z_pliku_stos_std(const char* sciezka, std::stack<int>& stos);

#endif