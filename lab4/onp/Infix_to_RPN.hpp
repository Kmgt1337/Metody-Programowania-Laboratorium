#ifndef INFIX_TO_RPN_HPP
#define INFIX_TO_RPN_HPP

#include <string>

// Pomocniczy typ wyliczeniowy do okreslania lacznosci operatora
enum class Associativity  
{
    left = 1,
    right = 2
};

/*
* Funkcja sprawdzajaca czy wyrazenie INF jest prawidlowe
* @param infix wyrazenie do sprawdzenia
* @returns true jesli wyrazenie jest prawidlowe
*/
bool f_check_if_infix_is_valid(std::string infix);

/*
* Funkcja sprawdzajaca czy znak jest operatorem
* @param alpha znak 
* @returns true jesli znak jest operatorem
*/
bool f_is_oper(char alpha);

/*
* Funkcja sprawdzajaca czy znak jest operatorem dwustronnym
* @param alpha znak 
* @returns true jesli znak jest operatorem dwustronnym
*/
bool f_is_double_oper(char alpha);

/*
* Funkcja sprawdzajaca czy znak jest nawiasem
* @param alpha znak 
* @returns true jesli znak jest nawiasem
*/
bool f_is_parenthesis(char alpha);

/*
* Funkcja okreslajaca priorytet operatora
* @param alpha znak 
* @returns priorytet operatora (0 jesli nie jest operatorem)
*/
int f_precedence (char alpha);

/*
* Funkcja okreslajaca lacznosc operatora
* @param alpha znak
* @returns jedna z dwoch wartosci typu wyliczeniowego (left albo right)
*/
Associativity f_associativity(char alpha);

/*
* Funkcja dokonujaca konwersji z notacji INF na ONP
* @param input wyrazenie wejsciowe
* @returns wyrazenie w postaci ONP (lub "error" jesli wyrazenie wejsciowe jest bledne)
*/
std::string f_infix_to_rpn(std::string input);

#endif