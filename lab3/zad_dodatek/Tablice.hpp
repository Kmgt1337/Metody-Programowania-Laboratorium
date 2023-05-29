#ifndef TABLICE_HPP
#define TABLICE_HPP

/*
* Funkcja tworzaca jednowymiarowa tablice dynamiczna
* @param rozmiar rozmiar tablicy
* @returns wskaznik do utworzonej tablicy
*/
int* f_stworz_tablice(int rozmiar);

/*
* Funkcja ktora usuwa dynamicznie stworzona tablice jednowymiarowa
* @param tab wskaznik do tablicy
*/
void f_usun_tablice(int* tab);


#endif