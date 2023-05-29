#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

// Klasa reprezentujaca przedmiot
class item
{
public:
    /*
    * Konstruktor
    * @param value wartosc przedmiotu
    * @param weight masa przedmiotu
    * @param name nazwa przedmiotu
    */
    item(int value, int weight, std::string name)
    {
        _weight = weight;
        _value = value;
        _name = name;
    }

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
    * Funkcja zwracajaca nazwe przedmiotu
    * @returns nazwe przedmiotu
    */
    std::string get_name() const {return _name; }

private:
    // masa przedmiotu
    int _weight;

    // wartosc przedmiotu
    int _value;

    // nazwa przedmiotu
    std::string _name;
};

// Klasa reprezentujaca pojedyczny zestaw danych zawierajaca vector przedmiotow, pojemnosc plecaka oraz informacje czy plecak moze byc wypelnione
class data_set
{
public:
    /*
    * Konstruktor
    * @param cap pojemnosc plecaka
    * @param weights vector wag
    * @param can_be_filled informacja czy plecak moze zostac wypelniony
    */
    data_set(int cap, std::vector<int> weights, bool can_be_filled)
        : _capacity{cap}, _weights{weights}, _can_be_filled{can_be_filled}
    {}

    /*
    * Funkcja zwracajaca pojemnosc plecaka
    * @returns pojemnosc plecaka
    */
    int get_capacity() const {return _capacity; }

    /*
    * Funkcja zwracajaca wagi przedmiotow 
    * @returns vector wag przedmiotow
    */
    std::vector<int> get_weights() const {return _weights; }

    /*
    * Funkcja zwracajaca informacje czy plecak moze zostac zapelnione
    * @returns informacja czy plecak moze zostac zapelniony
    */
    bool is_filled() const { return _can_be_filled; }

private:
    // pojemnosc plecaka
    int _capacity;

    // wagi przedmiotow
    std::vector<int> _weights;

    // informajca czy moze zostac wypelniony
    bool _can_be_filled;
};

/*
* Funkcja wykonujaca klasyczny algorytm plecakowy w formie dynamicznej. Mozna wielokrotnie uzywac tych samych przedmiotow. Tworzy dwuwymiarowy vector
* najlepszych upakowan plecaka P oraz skojarzony z nim dwuwymiarowy vector Q rzeczy pakowanych do plecaka w ostatnim ruchu
* @param items vector przedmiotow
* @param capacity pojemnosc plecaka
* @returns vector P oraz Q
*/
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> f_knapsack_dynamic(const std::vector<item>& items, int capacity);

/*
* Funkcja wyznaczajaca jakie przedmioty zostaly wlozone do plecaka i w jakiej kolejnosci na podstawie tablicy Q
* @param items vector przedmiotow
* @param Q dwuwymiarowy vector Q
* @returns vector przedmiotow wlozonych do plecaka w odpowiedniej kolejnosci
*/
std::vector<item> f_all_items_added_to_knapsack(const std::vector<item>& items, const std::vector<std::vector<int>>& Q);

/*
* Funkcja wyznaczajaca maksymalna wartosc jaka moze byc w plecaku na podstawie dwuwymiarowego vectora P
* @param P dwuwymiarowy vector P
* @returns maksymalna wartosc jaka moze byc w plecaku
*/
int f_get_maximum_value(const std::vector<std::vector<int>>& P);

/*
* Funkcja wykonujaca algorytm plecakowy w formie rekurencyjnej. Przedmioty musza idealnie wypelniac plecak.
* Funkcja dodatkowo wypisuje na ekran wykonywane kroki
* @param items vector przedmiotow
* @param items_fit_knapsack vector przedmiotow ktore wypelnia plecak (na poczatku jest to vector o rozmiarze 0)
* @param capacity pojemnosc plecaka
* @param pick aktualna suma wag badanych przedmiotow (na poczatku 0)
* @returns true jesli mozna wypelnic plecak, false jesli nie mozna
*/
bool f_knapsack_rec(const std::vector<int>& items, std::vector<int>& items_fit_knapsack, const int& capacity, int pick);

/*
* Szablon funkcji dokonujacej odwrocenia vectora dowolnego typu T
* @param T vector
*/
template<typename T>
void reverse_vec(std::vector<T>& v)
{
    reverse(v.begin(), v.end());
}

#endif