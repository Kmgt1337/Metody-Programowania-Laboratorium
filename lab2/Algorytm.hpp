#ifndef ALGORYTM_HPP
#define ALGORYTM_HPP

#include <string>

/*
* Klasa pomocnicza do przechowywania wyniku dzialania algorytmu
*/
struct C_wynik_algorytmu
{
    double najmniejszy_blad_mse; // najmniejszy blad mse
    unsigned int indeks; // indeks siatki dla ktorej jest najmniejszy blad mse
};

/*
* Funkcja obliczajaca minimalny blad mse
* @param siatki dwuwymiarowa tablica siatek silnika
* @param wiersze ilosc wierszy w tablicy siatek silnika
* @param kolumny ilosc kolumn w tablicy siatek silnika
* @param nieznany dwuwymiarowa tablica siatek nieznanego silnika
* @param bledy_mse jednowymiarowa tablica na bledy mse
* @returns minimalny blad mse oraz powiazany z nim indeks siatki silnika 
*/
C_wynik_algorytmu f_wyznacz_minimalny_blad_mse(double** siatki, unsigned int wiersze, unsigned int kolumny, double** nieznany, double* bledy_mse);

/*
* Funkcja okreslajaca z jakim silnikiem program pracuje (z silnikiem SEAK lub SEB)
* @param nazwa nazwa pliku tekstowego z ktorego pobierane sa dane silnika
* @returns liczbe oznaczajaca silnik (0: SEAK, 1: SEB, -1: nieznany silnik)
*/
int f_okresl_ktory_silnik(std::string nazwa);

#endif