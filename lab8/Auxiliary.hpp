#ifndef AUXILIARY_HPP
#define AUXILIARY_HPP
#include <limits>
#include <iostream>

/*
* Funkcja wczytujaca liczbe z zadanego przedzialu liczbowego
* @param min dolny zakres liczby
* @param max gorny zakres liczby
* @returns wczytana liczbe z zadanego przedzialu
*/
template <typename T>
T f_load_number(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
	T num;
	std::cin >> num;

	while (num < min || num > max)
	{
		std::cout << "!";
		std::cin >> num;
	}

	return num;
}

#endif