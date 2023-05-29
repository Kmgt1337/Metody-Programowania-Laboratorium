#ifndef ACG_GEN_HPP
#define ACG_GEN_HPP

#include <vector>
#include <utility>
#include <string>

class no_pair_found : std::exception
{
public:
    /*
    * Konstruktor klasy
    * @param msg wiadomosc
    */
    no_pair_found(const char* msg) : _message(msg)
    {}

    /*
    * Funkcja do odczytania wiadomosci przechowywanej przez klase
    * @returns wiadomosc
    */
    const char* what() const noexcept override
    {
        return _message.c_str();
    }

private:
    // skladnik przechowujacy wiadomosc
    std::string _message;
};

// Klasa generatora liczb pseudolosowych - addytywnego ACG
class ACG_gen
{
public:
    /*
    * Funkcja statyczna wczytujaca z pliku rekomendowane pary liczb dla generatora
    * @param path sciezka do pliku
    */
    static void init(const char* path);

    /*
    * Konstruktor klasy
    * @param n pierwsza liczba z pary
    * @param m druga liczba z pary
    */
    ACG_gen(int n, int m);

    /*
    * Funkcja zwracajaca kolejna obliczona liczbe pseudolosowa
    * @returns kolejna obliczona liczba pseudolosowa
    */
    int rand();

private:

    // pierwsza liczba z pary
    int _n;

    // druga liczba z pary
    int _m;

    // wyznaczona na podstawie rekomendowanych par liczb pierwsza liczba z pary
    int _j;

    // wyznaczona na podstawie rekomendowanych par liczb druga liczba z pary
    int _k;

    // rekomendowane pary liczb
    static std::vector<std::pair<int, int>> _pairs;

    // tablica liczb pseudolosowych wygenerowanych generatorem LCG
    std::vector<int> _Y;

    /*
    * Funkcja wybierajaca najlepsza pare liczb ze zbioru par rekomendowanych
    * @param pairs pary liczb rekomendowanych
    * @returns najlepsza pare
    */
    std::pair<int, int> choose_best_pair(const std::vector<std::pair<int, int>>& pairs);
};

#endif