#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

/*
* Funkcja obliczajaca rekurencyjnie wyrazenie a[0] + a[1]*x + a[2]*x2 + ... + a[N]*x^N
* @param N liczba naturalna 
* @param a wskaźnik do stalych typu int o dlugosci N + 1
* @param x liczba naturalna
* @returns obliczone wyrazenie
*/
int f_wielomian(int N, const int* a, int x);

/*
* Funkcja obliczajaca rekurencyjnie adres najwiekszego elementu tablicy
* @param N liczba naturalna
* @param t wskaznik do stalych typu int
* @returns adres najwiekszego elementu
*/
const int* f_maximum(int N, const int* t);

/*
* Funkcja obliczajaca symbol Newtona "N po K"
* @param N liczba naturalna
* @param K liczba naturalna
* @returns wartosc symbolu Newtona "N po K"
*/
int f_newton(int N, int K);

/*
* Funkcja pomocnicza do testowania funkcji "f_srednia_warunkowa"
* @param cos liczba typu int
* @returns true
*/
bool test_true(int cos);

/*
* Funkcja pomocnicza do testowania funkcji "f_srednia_warunkowa"
* @param cos liczba typu int
* @returns false
*/
bool test_false(int cos);

/*
* Funkcja obliczajaca srednia warunkowa wg. zadanego schematu
* @param s referencja do liczby typu double
* @param f wskaznik do funkcji przyjmujacej jeden argument typu int i zwracajacej bool
* @param b wskaznik do stalych typu int
* @param e wskaznik do stalych typu int
* @returns liczbe elementow z zakresu [b, e) dla ktorych wartosc f jest rowna true
*/
unsigned int f_srednia_warunkowa(double& s, bool(*f)(int), const int* b, const int* e);

/*
* Funkcja obliczajaca sume zadana wzorem a[0]*b[0]+a[1]*b[1]+...+a[n‐1]*b[n‐1] + a[n]*(1‐b[0]‐b[1]‐b[2]‐...‐b[n‐1]) 
* @param s referencja do liczby typu double
* @param b wskaznik do stalych typu double
* @param e wskaznik do stalych typu dobule
* @param a wskaznik do stalych typu double
* @returns true jesli zostaly spelnione wszystkie zalozenia
*/
bool f_suma_wazona(double& s, const double* b, const double* e, const double* a);

#endif