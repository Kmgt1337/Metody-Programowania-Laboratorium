#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include "Huffman.hpp"

/*
* Funckja ktora odczytuje z pliku tekst
* @param path sciezka do pliku
* @returns obiekt string z zapisanym tekstem
*/
std::string f_read_text_from_file(std::string path);

/*
* Funkcja ktora wczytuje znaki oraz ich prawdopodobienstwa/czestotliwosci
* @param path sciezka do pliku
* @returns mapa znakow oraz ich prawdopodobienstw/czestotliwosci
*/
std::unordered_map<char, float> f_read_chars_from_file(std::string path);

/*
* Funkcja ktora zapisuje do pliku rezultat dzialania programu
* @param path sciezka do pliku
* @param huffman obiekt klasy Huffman_coding zawierajacy informacje dotyczace przebiegu algorytmu
*/
void f_save_results_to_file(std::string path, Huffman_coding huffman);

#endif