#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include <utility>
#include <string>
#include <exception>
#include "Knapsack.hpp"

// Klasa bledu plikowego
class problem_with_file : std::exception
{
public:
    /*
    * Konstruktor klasy
    * @param msg wiadomosc
    */
    problem_with_file(const char* msg) : _message(msg)
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

/*
* Funkcja wczytujaca przedmioty oraz maksymalna pojemnosc plecaka z pliku (dla algorytmu dynamicznego)
* @param path sciezka do pliku
* @returns maksymalna pojemnosc plecaka oraz vector przedmiotow
*/
std::pair<int, std::vector<item>> f_load_items_from_file(const char* path);

/*
* Funkcja zapisujaca do pliku wynik dziala klasycznego algorytmu plecakowego w wersji dynamicznej
* @param path sciezka do pliku
* @param P dwuwymiarowy vector najlepszych upakowan plecaka
* @param Q dwuwymiarowy vector skojarzony z P rzeczy pakowanych do plecaka w ostatnim ruchu
* @param items przedmioty wlozone do plecaka dajace najwieksza wartosc
* @param max_value najwieksza wartosc mogaca byc w plecaku
*/
void f_save_dynamic_to_file(const char* path, const std::vector<std::vector<int>>& P, const std::vector<std::vector<int>>& Q, const std::vector<item>& items, int max_value);

/*
* Funkcja wczytujaca wagi przedmiotow oraz pojemnosc plecaka (dla algorytmu rekurencyjnego)
* @param path sciezka do pliku
* @returns obiekt klasy data_set
*/
std::vector<data_set> f_load_weights_from_file(const char* path);

/*
* Funkcja zapisujaca do pliku wynik dzialania algorytmu plecakowego rekurencyjnego
* @param path sciezka do pliku
* @param data vector klasy data_set zawierajacy informacje o przedmiotach wlozonych do plecaka
*/
void f_save_rec_to_file(const char* path, const std::vector<data_set>& data);

#endif