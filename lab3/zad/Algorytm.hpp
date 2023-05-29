#ifndef ALGORYTM_HPP
#define ALGORYTM_HPP

/*
* Funkcja wykonuje wyszukiwanie binarne zadanego elementu o najmniejszym indeksie
* @param tab uporzadkowana rosnaco tablica do przeszukania
* @param rozmiar rozmiar tablicy
* @param szukana szukana wartosc
* @returns najmniejszy indeks elementu (-1 jesli element nie wystepuje w tablicy)
*/
int f_wysz_binarne_najmniejszy_indeks(long long* tab, int rozmiar, int szukana);

/*
* Funkcja wykonuje wyszukiwanie binarne zadanego elementu o najwiekszym indeksie
* @param tab uporzadkowana rosnaco tablica do przeszukania
* @param rozmiar rozmiar tablicy
* @param szukana szukana wartosc
* @returns najwiekszy indeks elementu (-1 jesli element nie wystepuje w tablicy)
*/
int f_wysz_binarne_najwiekszy_indeks(long long* tab, int rozmiar, int szukana);

/*
* Funkcja zlicza ile razy zadany element wystepuje w tablicy
* @param tab uporzadkowana rosnaco tablica
* @param rozmiar rozmiar tablicy
* @param szukana wartosc do zliczenia
* @returns ilosc zadanych elementow
*/
int f_zlicz_ile_elementow(long long* tab, int rozmiar, int szukana);

/*
* Funkcja wykonuje wyszukiwanie interpolacyjne zadanego elementu w tablicy
* @param tab uporzadkowana rosnaco tablica do przeszukania
* @param rozmiar rozmiar tablicy
* @param szukana szukana wartosc
* @returns indeks elementu (-1 jesli element nie wystepuje w tablicy, 0 jesli wszystkie elementy sa rowne szukanej wartosci)
*/
int f_wysz_interpolacyjne(long long* tab, int rozmiar, int szukana);

/*
* Funkcja usuwajaca duplikaty z tablicy
* @param tab uporzadkowana rosnaco tablica
* @param rozmiar rozmiar tablicy
* @returns rozmiar nowej tablicy
*/
int f_usun_duplikaty(long long* tab, int rozmiar);

#endif