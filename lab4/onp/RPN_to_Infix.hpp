#ifndef RPN_TO_INFIX_HPP
#define RPN_TO_INFIX_HPP

#include <string>
#include <vector>

/*
* Funkcja okreslajaca priorytet operatora
* @param alpha znak 
* @returns priorytet operatora (0 jesli nie jest operatorem)
*/
int f_precedence(std::string alpha);

/*
* Funkcja dononujaca konwersji z ONP na INF
* @param input wyrazenie wejsciowe
* @returns wyrazenie w postaci INF (lub "error" jesli wyrazenie wejsciowe jest bledne)
*/
std::string f_rpn_to_infix(std::string input);

#endif