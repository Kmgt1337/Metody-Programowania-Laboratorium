#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

#include "List.hpp"

// Pomocnicza klasa do przechowywania rozmiaru dwuwymiarowej tablicy (macierzy)
struct C_matrix_size
{
    // liczba wierszy
    unsigned int rows;

    // liczba kolumn
    unsigned int cols;
};

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
    const char* what() 
    {
        return _message.c_str();
    }

private:
    // skladnik przechowujacy wiadomosc
    std::string _message;
};

/*
* Funkcja wczytujaca z pliku rozmiar macierzy (tablicy dwuwymiarowej)
* @param path sciezka do pliku
* @returns obiekt klasy C_matrix_size przechowujacy rozmiar tablicy
*/
C_matrix_size f_read_matrix_size_from_file(const char* path);

/*
* Funkcja wczytujaca krawedzie z pliku tekstowego
* @param path sciezka do pliku
* @param m_size rozmiar macierzy (tablicy dwuwymiarowej)
* @returns wskaznik do tablicy przechowujacej krawedzie
*/
int* f_read_edges_from_file(const char* path, C_matrix_size m_size);

/*
* Funkcja zapisujaca do pliku wyniki pierwszego zadania
* @param path sciezka do pliku
* @param incidence_matrix macierz incydencji grafu (tablica dwuwymiarowa)
* @param neighbours sasiedzi kazdego wierzcholka (tablia dwuwymiarowa)
* @param incidence_vector macierz incydencji grafu (std::vector dwuwymiarowy)
* @param neighbours_vec sasiedzi kazdego wierzcholka (dwuwymiarowy std::vector)
*/
void f_save_to_file_first(const char* path, int** incidence_matrix, C_matrix_size m_size, int** neighbours, std::vector<std::vector<int>> incidience_vector, const std::vector<std::vector<int>>& neighbours_vec);

/*
* Funkcja zapisujaca do pliku wyniki drugiego zadania
* @param path sciezka do pliku
* @param inc_list tablica list incydencji grafu (std::vector list typu C_linked_list)
* @param inc_list_sec tablica list incydencji (std::vector list typu std::list)
* @param d_list tablica list zawierajaca stopnie wierzcholkow grafu (std::vector list typu std::list)
* @param d_list_second tablica list zawierajaca stopnie wierzcholkow grafu (std::vector list std::typu) 
*/
void f_save_to_file_second(const char* path, const std::vector<C_linked_list>& inc_list, const std::vector<std::list<int>>& inc_list_sec, const std::vector<std::list<int>>& d_list, const std::vector<std::list<int>>& d_list_second);

#endif