#ifndef PLIKI_HPP
#define PLIKI_HPP

// Klasa do przechowywania pojedynczego zestawu danych
class C_zestaw_danych
{
public:
    /*
    * Konstruktor klasy wczytujacy z pliku zestaw danych
    * @param sciezka sciezka do pliku
    */
    C_zestaw_danych(const char* sciezka);

    /*
    * Destruktor klasy
    */
    ~C_zestaw_danych();

    // rozmiar tablicy zestawu danych
    int rozmiar_zestawu_danych;

    // rozmiar tablicy zestawu zapytan (kluczy)
    int rozmiar_zestawu_zapytan;

    // dynamiczna tablica zestawu danych
    long long* zestaw_danych;

    // dynamiczna tablica zestawu zapytan (kluczy)
    long long* zestaw_zapytan;

    // zmienna statyczna okreslajaca od ktorej linii pliku ma rozpoczac sie wczytywanie zestawu danych (w przypadku gdy zestawow jest wiecej niz jeden)
    static int obecna_linia;
};

/*
* Funkcja wczytujaca z pliku ilosc zestawow danych 
* @param sciezka sciezka do pliku
* @returns ilosc zestawow danych
*/
int f_wczytaj_ilosc_zestawow_danych(const char* sciezka);

/*
* Funkcja zapisujaca do pliku pierwsza serie wynikow
* @param sciezka sciezka do pliku
* @param I tablica zawierajaca liczbe elementow tablicy o zadanej wartosci
* @param J tablica zawierajaca indeks tablicy dla zadanej wartosci (-1 gdy nie zawiera danej wartosci w tablicy, 0 gdy wszystkie wartosci tablicy sa rowne zadanej wartosci)
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_zapisz_do_pliku_pierwszy_wynik(const char* sciezka, long long* I, long long* J, int rozmiar);

/*
* Funkcja zapisujaca do pliku druga serie wynikow
* @param sciezka sciezka do pliku
* @param tab tablica po usunieciu duplikatow
* @param rozmiar rozmiar tablicy po usunieciu duplikatow
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_zapisz_do_pliku_drugi_wynik(const char* sciezka, long long* tab, int rozmiar);

/*
* Funkcja tworzy odpowiednio sformatowany plik z losowymi danymi
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_stworz_plik_z_losowymi_danymi();

#endif