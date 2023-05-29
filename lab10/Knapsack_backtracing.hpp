#ifndef KNAPSACK_BACKTRACING_HPP
#define KNAPSACK_BACKTRACING_HPP

#include "Utility.hpp"
#include <vector>

// Klasa rozwiazujaca problem plecakowy 0-1 za pomoca algorytmu z nawrotami z elementami programowania zachlannego
class Knapsack_backtracing
{
public:
    /*
    * Konstruktor klasy
    * @param W maksymalna pojemnosc plecaka
    * @param items vector przedmiotow
    */
    Knapsack_backtracing(int W, const std::vector<Item>& items);

    /*
    * Funkcja rekurencyjna rozwiazujaca problem plecakowy 0-1 za pomoca algorytmu z nawrotami
    * @param level_index obecna glebokosc w drzewie (na poczatek 0)
    * @param profit aktualny zysk (na poczatek 0)
    * @param weight aktualna waga (na poczatek 0)
    */
    void knapsack(int level_index, int profit, int weight);

    /*
    * Funkcja zwracajaca maksymalny zysk
    * @returns maksymalny zysk
    */
    int best_value() {return _mp; }

    /*
    * Funkcja zwracajaca odwiedzone wierzcholki
    * @returns odwiedzone wierzcholki
    */
    std::vector<Node> give_nodes() {return _nodes; }

    /*
    * Funkcja zwracajaca obiekt klasy Reporter
    * @returns obiekt klasy Reporter
    */
    Reporter give_reporer() {return _rep; }

private:
    /*
    * Funkcja obliczajaca aktualny "bound" dla algorytmu z nawrotami
    * @param level_index obecna glebokosc w drzewie
    * @param profit aktualny zysk
    * @param weight aktualna masa
    */
    int calculate_bound(int level_index, int profit, int weight);

    /*
    * Funkcja okreslajaca czy aktualny wierzcholek jest obiecujacy czy nie za pomoca warunku z "bound"
    * @param bound aktualny "bound"
    * @returns true jesli wierzcholek jest obiecujacy, false jesli nie
    */
    bool promising(int bound);

    // maksymalny zysk
    int _mp;

    // maksymalna masa plecaka
    int _W;

    // vector przedmiotow
    std::vector<Item> _items;

    // vector odwiedzonych wierzcholkow
    std::vector<Node> _nodes;

    // reporter 
    Reporter _rep;
};

#endif