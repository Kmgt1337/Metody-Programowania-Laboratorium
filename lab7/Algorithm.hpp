#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <utility>
#include <vector>

/*
* Funkcja wyszukujaca iteracyjnie pierwsze wystapienie leksykograficzne zadanego elementu w tablicy 2D. Zloznosc O(n*log(m)), n - liczba wierszy, m - liczba kolumn
* @param matrix tablica 2D
* @param key element do wyszukania
* @returns indeks znalezionego elementu. W przypadku braku wystapienia zwraca (-1, -1)
*/
std::pair<int, int> f_search_first_occuerence_iter(const std::vector<std::vector<int>>& matrix, int key);

/*
* Funkcja wyszukujaca iteracyjnie ostatnie wystapienie leksykograficzne zadanego elementu w tablicy 2D. Zloznosc O(n*log(m)), n - liczba wierszy, m - liczba kolumn
* @param matrix tablica 2D
* @param key element do wyszukania
* @returns indeks znalezionego elementu. W przypadku braku wystapienia zwraca (-1, -1)
*/
std::pair<int, int> f_search_last_occuerence_iter(const std::vector<std::vector<int>>& matrix, int key);

/*
* Funkcja wyszukujaca rekurencyjnie (wywoluje funkcje rekurencyjna) pierwsze wystapienie leksykograficzne zadanego elementu w tablicy 2D. Zloznosc O(n*log(m)), n - liczba wierszy, m - liczba kolumn
* @param matrix tablica 2D
* @param key element do wyszukania
* @returns indeks znalezionego elementu. W przypadku braku wystapienia zwraca (-1, -1)
*/
std::pair<int, int> f_search_first_occuerence_rec(const std::vector<std::vector<int>>& matrix, int key);

/*
* Funkcja wyszukujaca rekurencyjnie (wywoluje funkcje rekurencyjna) ostatnie wystapienie leksykograficzne zadanego elementu w tablicy 2D. Zloznosc O(n*log(m)), n - liczba wierszy, m - liczba kolumn
* @param matrix tablica 2D
* @param key element do wyszukania
* @returns indeks znalezionego elementu. W przypadku braku wystapienia zwraca (-1, -1)
*/
std::pair<int, int> f_search_last_occuerence_rec(const std::vector<std::vector<int>>& matrix, int key);

/*
* Funkcja rekurencyjna wyszukujaca pierwsze wystapienie zadanego elementu w tablicy 1D. Zlozonosc O(log(n)), n - rozmiar tablicy
* @param arr tablica 1D
* @param low element startowy
* @param high element koncowy
* @param key element do wyszukania
* @returns indeks znalezionego elementu. W przypadku braku wystapienia zwraca -1
*/
int f_first_occurence_binary_rec(const std::vector<int>& arr, int low, int high, int key);

/*
* Funkcja rekurencyjna wyszukujaca ostatnie wystapienie zadanego elementu w tablicy 1D. Zlozonosc O(log(n)), n - rozmiar tablicy
* @param arr tablica 1D
* @param low element startowy
* @param high element koncowy
* @param key element do wyszukania
* @returns indeks znalezionego elementu. W przypadku braku wystapienia zwraca -1
*/
int f_last_occurence_binary_rec(const std::vector<int>& arr, int low, int high, int key);

#endif