#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <vector>
#include <algorithm>

// Klasa reprezentujaca przedmiot
class Item
{
public:
    /*
    * Konstruktor
    * @param value wartosc przedmiotu
    * @param weight masa przedmiotu
    * @param on status przedmiotu (domyslnie true)
    */
    Item(int value, int weight, bool on = true)
    {
        _weight = weight;
        _value = value;
        _ratio = value / weight;
        _online = on;
    }

    /*
    * Funkcja zmieniajaca status przedmiotu na zadany
    * @param b status przedmiotu
    */
    void change_state_to(bool b) {_online = b;}

    /*
    * Funkcja zwracajaca mase przedmiotu
    * @returns masa przedmiotu
    */
    int get_weight() const { return _weight; }

    /*
    * Funkcja zwracajaca wartosc przedmiotu
    * @returns wartosc przedmiotu
    */
    int get_value() const {return _value; }

    /*
    * Funkcja zwracajaca wspolczynnik p/w przedmiotu
    * @returns wspolczynnik p/w przedmiotu
    */
    double get_ratio() const {return _ratio; }

    /*
    * Funkcja zwracajaca status przedmiotu
    * @returns status przedmiotu
    */
    bool is_online() const { return _online; }

private:
    // wartosc przedmiotu
    int _value;

    // masa przedmiotu
    int _weight;

    // wspolczynnik p/w przedmiotu
    double _ratio;

    // status przedmiotu
    bool _online;
};

// Klasa reprezentujaca wezel w drzewie generowanym przez algorytm
class Node
{
public:
    /*
    * Konstruktor
    * @param level glebokosc wierzcholka
    * @param location wspolrzedna "y" wierzcholka
    * @param profit wartosc wierzcholka
    * @param bound bound wierzcholka
    * @param mp maksymalny zysk wierzcholka
    */
    Node(int level, int location, int profit, int weight, int bound, int mp)
    {
        _level = level;
        _location = location;
        _profit = profit;
        _weight = weight;
        _bound = bound;
        _mp = mp;
    }

    /*
    * Funkcja zmieniajaca maksymalny zysk wierzcholka
    * @param mp maksymalny zysk wierzcholka
    */
    void change_mp(int mp){ _mp = mp; }

    /*
    * Funkcja zmieniajaca bound wierzcholka
    * @param b bound wierzcholka 
    */
    void change_bound(int b){ _bound = b; }

    /*
    * Funkcja zmieniajaca wspolrzedna "y" wierzcholka
    * @param y wspolrzedna "y" wierzcholka
    */
    void change_location(int y){ _location = y; }

    /*
    * Funkcja zwracajaca glebokosc wierzcholka
    * @returns glebokosc wierzcholka
    */
    int get_level() const {return _level; }

    /*
    * Funkcja zwracajaca wspolrzedna "y" wierzcholka
    * @returns wspolrzedna "y" wierzcholka
    */
    int get_location() const {return _location; }

    /*
    * Funkcja zwracajaca zysk wierzcholka
    * @returns zysk wierzcholka
    */
    int get_profit() const {return _profit; }

    /*
    * Funkcja zwracajaca mase wierzcholka
    * @returns mase wierzcholka
    */
    int get_weight() const {return _weight; }

    /*
    * Funkcja zwracajaca bound wierzcholka
    * @returns bound wierzcholka
    */
    int get_bound() const {return _bound; }

    /*
    * Funkcja zwracajaca maksymalny zysk wierzcholka
    * @returns maksymalny zysk wierzcholka
    */
    int get_mp() const {return _mp; }

private:
    // glebokosc wierzcholka
    int _level;

    // wspolrzedna "y" wierzcholka
    int _location; 

    // zysk wierzcholka
    int _profit;

    // masa wierzcholka
    int _weight;

    // bound wierzcholka
    int _bound;

    // maksymalny zysk wierzcholka
    int _mp;
};

// Klasa reprezentujaca reportera czyli klasa zapisujaca przebieg dzialania algorytmu
class Reporter
{
public:
    // Konstruktor
    Reporter() { message = "";}

    /*
    * Funkcja dodajaca przesylana wiadomosc do calej wiadomosci
    * @param msg wiadomosc do dodania
    */
    void report(std::string msg)
    {
        message += msg;
    }

    /*
    * Funkcja zwracajaca wiadomosc przechowywana przez klase
    * @returns wiadomosc
    */
    std::string give_message() const
    {
        return message;
    }

private:
    // wiadomosc
    std::string message;
};

/*
* Funkcja obliczajaca wspolrzedna "y" wierzcholka
* @param level glebokosc wierzcholka (jego wspolrzedna "x")
* @param nodes vector do tej pory odwiedzonych wierzcholkow
*/
int calculate_position(int level, const std::vector<Node>& nodes);

#endif