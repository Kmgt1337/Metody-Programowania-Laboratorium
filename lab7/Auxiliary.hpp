#ifndef AUXILIARY_HPP
#define AUXILIARY_HPP

#include <utility>
#include <vector>

// Klasa pomocnicza do przechowywania wyniku dzialania algorytmow wyszukujacych indeks zadanego elementu w tablicy 2D
class C_result
{
public:
    // indeks znalezionego najmniejszego elementu iteracyjnie
    std::pair<int, int> iter_low;

    // indeks znalezionego najwiekszego elementu iteracyjnie
    std::pair<int, int> iter_high;

    // indeks znalezionego najmniejszego elementu rekurencyjnie
    std::pair<int, int> rec_low;

    // indeks znalezionego najwiekszego elementu rekurencyjnie
    std::pair<int, int> rec_high;

    // szukany element
    int key;
};

#endif