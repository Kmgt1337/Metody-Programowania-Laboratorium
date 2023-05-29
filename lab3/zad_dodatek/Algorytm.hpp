#ifndef ALGORYTM_HPP
#define ALGORYTM_HPP

/*
* Funkcja obliczajaca wszystkie podzbiory zbioru n-elementowego i zapisujaca je do pliku w postaci ciagow binarnych
* @param n dlugosc ciagu wejsciowego
* @param sciezka sciezka pliku do zapisu wynikow
*/
void f_znajdz_wszystkie_podzbiory(int n, const char* sciezka);

/*
* Funkcja obliczajaca wszystkie k-elementowe podzbiory zbioru n-elementowego i zapisuje je w porzadku leksykograficznym do pliku
* @param n dlugosc ciagu wejsciowego
* @param k dlugosc podzbioru
* @param sciezka sciezka pliku do zapisu wynikow
*/
void f_znajdz_wszystkie_kelementowe_podzbiory(int n, int k, const char* sciezka);

/*
* Funkcja obliczajaca podzialy liczby n i zapisujaca je do pliku
* @param n zadana liczba
* @param sciezka sciezka pliku do zapisu danych
*/
void f_znajdz_podzialy_liczby(int n, const char* sciezka);

#endif