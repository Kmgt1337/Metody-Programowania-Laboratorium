#ifndef PLIKI_HPP
#define PLIKI_HPP

#include <fstream>
#include <string>
#include <sstream>
#include "Tablice.hpp"
#include "Algorytm.hpp"

/*
* Klasa pomocnicza do przechowywania ilosci wierszy i kolumn dla tablicy dwuwymiarowej
*/
struct C_wiersze_kolumny
{
	unsigned int wiersze; // ilosc wierszy 
	unsigned int kolumny; // ilosc kolumn
};

/*
* Funkcja zapisujaca do pliku tekstowego wynik dzialania programu
* @param sciezka sciezka pliku tekstowego
* @param wynik wynik dzialania algorytmu, najmniejszy blad mse i powiazany z nim indeks siatki
* @param bledy_mse tablica jednowymiarowa przechowujaca bledy mse
* @param siatki tablica dwuwymiarowa przechowujaca siatki silnika
* @param wiersze ilosc wierszy w tablicy siatek silnika
* @param kolumny ilosc kolumn w tablicy siatek silnika
* @returns prawda lub falsz
*/
bool f_zapisz_wyniki(const char* sciezka, C_wynik_algorytmu wynik, double* bledy_mse, double** siatki, unsigned int wiersze, unsigned int kolumny);

/*
* Funkcja odczytujaca z pliku tekstowego ilosc wierszy i kolumn siatek silnika
* @param sciezka sciezka do pliku tekstowego
* @returns ilosc wierszy i kolumn
*/
C_wiersze_kolumny f_odczytaj_liczbe_wierszy_i_kolumn_z_pliku(const char* sciezka);

/*
* Funkcja wczytujaca siatki silnika z pliku tekstowego i tworzaca dynamiczna tablice dwuwymiarowa
* @param sciezka sciezka pliku tekstowego
* @param wiersze ilosc wierszy w pliku siatek silnika
* @param kolumny ilosc kolumn w pliku siatek silnika 
* @returns wskaznik do utworzonej tablicy dwuwymiarowej
*/
double** f_odczytaj_dane_z_pliku(const char* sciezka, int wiersze, int kolumny);

#endif