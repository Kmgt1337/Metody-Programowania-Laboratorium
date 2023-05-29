#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include <string>
#include "Auxiliary.hpp"

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

// Klasa do przechowywania pojedynczego zestawu danych
class C_data
{
public:
    // tablica 2D
    std::vector<std::vector<int>> matrix;

    // liczba wierszy
    std::size_t rows;

    // liczba kolumn
    std::size_t cols;

    // szukany element
    int key;
};

/*
* Funkcja wczytujaca z pliku zestawy danych
* @param path sciezka do pliku
* @returns zestawy danych 
*/
std::vector<C_data> f_read_data_from_file(const char* path);

/*
* Funkcja zapisujaca do pliku wyniki dzialania algorytmow
* @param path sciezka do pliku
* @param results wyniki 
*/
void f_save_results_to_file(const char* path, const std::vector<C_result>& results);

#endif