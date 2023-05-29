#ifndef WIZUALIZACJA_HPP
#define WIZUALIZACJA_HPP

#include <string>

/*
* Klasa odpowiedzialna za wykonanie wykresu w programie Gnuplot
* Klasa tworzy dynamicznie wykres w "wizualizacja/wykres.png"
*/
class Wizualizacja
{
public:
    /*
    * Konstruktor klasy Wizualizacja. Tworzy pliki tekstowe potrzebne dla programu Gnuplot
    * @param sciezka_programu sciezka do pliku wykonywalnego programu
    * @param siatki_silnika siatki silnika pobrane z pliku tekstowego
    * @param indeks_dopasowanej indeks siatki silnika zawierajacej najmniejszy blad mse
    * @param siatki_nieznanego siatki nieznanego silnika pobrane z pliku tekstowego
    * @param wiersze liczba wierszy siatek silnika
    * @param kolumny liczba kolumn siatek silnika
    * @param ktory_silnik liczba wskazujaca z jakim silnikiem pracuje program (0: SEAK, 1: SEB, -1: nieznany silnik)
    */
    Wizualizacja(const char* sciezka_programu, double** siatki_silnika, unsigned int indeks_dopasowanej, double** siatki_nieznanego, unsigned int wiersze, unsigned int kolumny, int ktory_silnik);

    /*
    * Funkcja ktora uruchamia program Gnuplot i wykonuje w nim wykres
    */
    void uruchom_skrypt();
    
private:
    std::string sciezka_skryptu; // sciezka do pliku tekstowego zawieracajacego skrypt dla programu Gnuplot
    std::string sciezka_danych_silnika; // sciezka do pliku tekstowego zawieracajacego dane wektora silnika
    std::string sciezka_danych_nieznanego; // sciezka do pliku tekstowego zawierajacego dane wektora nieznanego silnika
};

#endif