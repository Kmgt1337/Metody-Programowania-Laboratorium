#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <list>
#include "List.hpp"
#include "File.hpp"

/*
* Funkcja tworzaca macierz incydencji grafu
* @param edges krawedzie grafu
* @param rows liczba wierszy macierzy
* @param cols liczba kolumn macierzy
* @returns wskaznik do tablicy dwuwymiarowej
*/
int** f_create_incidence_matrix(int* edges, int rows, int cols);

/*
* Funkcja tworzaca macierz incydencji grafu
* @param path sciezka do pliku
* @param cols liczba kolumn macierzy
* @returns dwuwymiarowy std::vector
*/
std::vector<std::vector<int>> f_create_incidence_vector(const char* path, int cols);

/*
* Funkcja obliczajaca wszystkich sasiadow wierzcholku w grafie
* @param incidence_matrix macierz incydencji grafu
* @param rows liczba wierszy w macierzy
* @param cols liczba kolumn w macierzy
* @returns wskaznik do tablicy dwuwymiarowej
*/
int** f_calculate_all_neighbours_of_vertex(int** incidence_matrix, int rows, int cols);

/*
* Funkcja obliczajaca wszystkich sasiadow wierzcholku w grafie
* @param incidence_matrix macierz incydencji
* @returns wektor dwuwymiarowy
*/
std::vector<std::vector<int>> f_calculate_all_neighbours_of_vertex(const std::vector<std::vector<int>>& incidence_matrix);

/*
* Funkcja dodajaca do tablicy incydencji krawedz grafu
* @param list tablica list incydencji
* @param src wierzcholek z ktorego idziemy
* @param dst wierzcholek do ktorego idziemy
*/
void f_add_edge(std::vector<C_linked_list>& list, int src, int dst);

/*
* Funkcja dodajaca do tablicy incydencji krawedz grafu
* @param list tablica list incydencji
* @param src wierzcholek z ktorego idziemy
* @param dst wierzcholek do ktorego idziemy
*/
void f_add_edge(std::vector<std::list<int>>& list, int src, int dst);

/*
* Funkcja tworzaca tablice list incydencji
* @param edgres krawedzie grafu
* @param size rozmiar tablicy
* @returns tablica list incydencji
*/
std::vector<C_linked_list> f_create_incidence_list(int* edges, C_matrix_size size);

/*
* Funkcja tworzaca tablice list incydencji
* @param edgres krawedzie grafu
* @param size rozmiar tablicy
* @returns tablica list incydencji
*/
std::vector<std::list<int>> f_create_incidence_list_std(int* edges, C_matrix_size size);

/*
* Funkcja obliczajaca stopnie wszystkich wierzcholkow w grafie
* @param incidence_list tablica list incydencji
* @param num_of_vertex liczba wierzcholkow w grafie
* @returns tablica list incydencji
*/
std::vector<std::list<int>> f_calculate_vertexes_degree(const std::vector<C_linked_list>& incidence_list, int num_of_vertex);

/*
* Funkcja obliczajaca stopnie wszystkich wierzcholkow w grafie
* @param incidence_list tablica list incydencji
* @param num_of_vertex liczba wierzcholkow w grafie
* @returns tablica list incydencji
*/
std::vector<std::list<int>> f_calculate_vertexes_degree_std(const std::vector<std::list<int>>& incidence_list, int num_of_vertex);

#endif