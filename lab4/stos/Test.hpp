#ifndef TEST_HPP
#define TEST_HPP

#include <stack>
#include "Stos_tabl.hpp"
#include "Stos_lista.hpp"

/*
* Funkcja testujaca implementacje stosow i zapisujaca wyniki do pliku
* @param stos_tabl stos oparty na tablicy dynamicznej
* @param stis_lista stos oparty na liscie jednokierunkowej
* @param stos_std standardowa implementacja stosu std::stack
*/
void f_testuj_stosy(Stos_tbl<int>& stos_tabl, Stos_lista<int>& stos_lista, std::stack<int>& stos_std);

#endif