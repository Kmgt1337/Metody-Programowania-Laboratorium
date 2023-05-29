#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include <string>
#include <exception>
#include <utility>
#include "Utility.hpp"

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
* Funkcja wczytujaca z pliku dane potrzebne do dzialania programu
* @param path sciezka do pliku
* @returns maksymalna waga plecaka oraz vector przedmiotow
*/
std::pair<int, std::vector<Item>> f_load_items_from_file(const char* path);

/*
* Funkcja zapisujaca do pliku wynik dzialania programu
* @param path sciezka do pliku
* @param items vector przedmiotow
* @param nodes vector odwiedzonych wierzcholkow
* @param rep obiekt klasy "Reporter" zawierajacy string z przebiegiem dzialania algorytmu
* @param mp najwiekszy zysk
*/
void f_save_to_file(const char* path, const std::vector<Item>& items, const std::vector<Node>& nodes, const Reporter& rep, int mp);

#endif