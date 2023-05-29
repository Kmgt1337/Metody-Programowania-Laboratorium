#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include <utility>
#include <string>
#include <exception>

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
* Funkcja wczytuajca z pliku pary liczb
* @param path sciezka do pliku
* @returns pary liczb 
*/
std::vector<std::pair<int, int>> f_load_pairs_from_file(const char* path);

/*
* Funkcja zapisujaca do pliku wygenerowane liczby pseudolosowe
* @param path sciezka do pliku
* @param vec tablica liczb
*/
void f_save_to_file(const char* path, const std::vector<int>& vec);

#endif