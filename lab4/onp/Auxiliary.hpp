#ifndef AUXILIARY_HPP
#define AUXILIARY_HPP

#include <string>
#include <vector>

/*
* Funkcja usuwajaca biale i niepoprawne znaki z wyrazenia
* @param input wejsciowe wyrazenie 
* @returns wyrazenie bez bialych i niepoprawnych znakow
*/
std::string f_delete_white_spaces_and_wrong_chars(std::string input);

/*
* Funkcja dokonujaca konwersji z string na wektor pojedyncznych stringow
* @param input string wejsciowy
* @returns wektor pojedycznych stringow
*/
std::vector<std::string> f_convert_string_to_vector(std::string input);

#endif