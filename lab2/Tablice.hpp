#ifndef TABLICE_HPP
#define TABLICE_HPP

/*
* Funkcja tworzaca jednowymiarowa tablice dynamiczna
* @param rozmiar rozmiar tablicy
* @returns wskaznik do utworzonej tablicy
*/
double* f_stworz_tablice(int rozmiar);

/*
* Funkcja ktora usuwa dynamicznie stworzona tablice jednowymiarowa
* @param tab wskaznik do tablicy
*/
void f_usun_tablice(double* tab);

/*
* Funkcja tworzaca dwuwymiarowa tablice dynamiczna
* @param wiersze ilosc wierszy tablicy
* @param kolumny ilosc kolumny tablicy
* @returns wskaznik do utworzonej tablicy
*/
double** f_stworz_tablice_2D(int wiersze, int kolumny);

/*
* Funkcja ktora usuwa dynamicznie stworzona tablice dwuwymiarowa
* @param tab wskaznik do tablicy
* @param wiersze ilosc wierszy
*/
void f_usun_tablice_2D(double** tab, int wiersze);

#endif