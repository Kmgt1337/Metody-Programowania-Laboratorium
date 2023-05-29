#ifndef FILE_HPP
#define FILE_HPP

#include <vector>
#include <string>
#include <utility>

/*
* Funkcja wczytujaca dane z pliku i zapisujaca je do wektora par stringow
* @param source sciezka do pliku
* @param inputs wektor par stringow do ktorego funkcja zapisuje dane z pliku
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_read_from_file(const char* source, std::vector<std::pair<std::string, std::string>>& inputs);

/*
* Funkcja zapisujaca dane do pliku
* @param source sciezka do pliku
* @param outputs wektor par stringow z ktorego zostana zapisane wyniki do pliku
* @returns true jesli funkcja wykonala prace prawidlowo
*/
bool f_save_to_file(const char* file, const std::vector<std::pair<std::string, std::string>>& outputs);

#endif