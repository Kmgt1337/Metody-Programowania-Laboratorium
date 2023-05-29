#ifndef PLIKI_HPP
#define PLIKI_HPP

/*
* Funkcja czyszczaca plik wynikowy przed przystapieniem do jej zapelniania
* @param sciezka sciezka pliku do zapisu
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_wyczysc_plik(const char* sciezka);

/*
* Funkcja zapisujaca do pliku kolejne ciagi binarne (podzbiory zbioru n-elementowego)
* @param sciezka sciezka pliku do zapisu
* @param B tablica reprezentujaca ciag binarny
* @param rozmiar rozmiar tablicy pomniejszony o 1 
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_pisz_do_pliku(const char* sciezka, int* B, int rozmiar);


/*
* Funkcja zapisujaca do pliku podzialy liczby n
* @param sciezka sciezka do pliku
* @param S zawiera parami rozne skladniki podzialu
* @param R R[i] okresla informacje ile razy skladnik S[i] wystepuje w podziale
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_pisz_do_pliku_podzialy(const char* sciezka, int* S, int* R, int rozmiar);

#endif