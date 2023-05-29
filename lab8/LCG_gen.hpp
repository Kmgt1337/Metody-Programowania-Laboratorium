#ifndef LCG_GEN_HPP
#define LCG_HEN_HPP

#include <vector>

// Klasa generatora liczb pseudolosowych: kongruentnego LCG
class LCG_gen
{
public:
    /*
    * Konstruktor klasy
    * @param x_min dolny zakres liczb do losowania
    * @param x_max gorny zakres liczb do losowania
    * @param seed ziarno generatora
    */
    LCG_gen(int x_min, int x_max, int seed);

    /*
    * Funkcja zwracajaca kolejna obliczona liczbe pseudolosowa
    * @returns kolejna obliczona liczba pseudolosowa
    */
    int rand();

private:
    /*
    * Funkcja obliczajaca wspolczynnik "c" generatora, czyli jego "krok"
    * @returns krok generatora
    */
    int calc_increment();

    /*
    * Funkcja obliczajaca wspolczynnik "a" generatora, czyli jego "mnoznik"
    * @returns mnoznik generatora
    */
    int calc_multiplier();

    /*
    * Funkcja sprawdzajaca dla danej liczby "b" twierdzenie: b = a-1 jest wielokrotnością każdej liczby pierwszej p, która jest dzielnikiem m
    * @param b liczba do sprawdzenia
    * @returns prawda - jesli twierdzenie jest spelnione, falsz - jesli nie jest spelnione
    */
    bool check_second_statement(int b);

    /*
    * Funkcja sprawdzajaca dla danej liczby "b" twierdzenie: b jest wielokrotnością 4, o ile m jest również wielokrotnością 4
    * @param b liczba do sprawdzenia
    * @returns prawda - jesli twierdzenie jest spelnione, falsz - jesli nie jest spelnione
    */
    bool check_third_statement(int b);

    /*
    * Funkcja wykonujaca rozklad na czynniki pierwsze danej liczby n
    * @param n dana liczba
    * @returns jej czynniki pierwsze
    */
    std::vector<int> calc_primes(int n);

    // modul generatora
    int _m;

    // krok generatora
    int _c;

    // mnoznik generatora
    int _a;

    // poprzednia obliczona liczba pseudoloswoa
    int _prev;

    // dolny zakres liczb do losowania
    int _x_min;

    // gorny zakres liczb do losowania
    int _x_max;

    // czynniki pierwsze modulu generatora
    std::vector<int> _primes_m;
};

#endif