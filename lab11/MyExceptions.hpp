#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include <stdexcept>

// przestrzen nazw zawierajaca moje nowo napisane wyjatki 
namespace myexceptions
{   
    // Klasa bledu otwarcia pliku
    class FileOpenException : public std::runtime_error
    {
    public:
        /*
        * Konstruktor
        */
        FileOpenException() : runtime_error("Nie mozna otworzyc pliku!")
        {}

        /*
        * Konstruktor
        * @param msg wiadomosc do bledu
        */
        FileOpenException(std::string msg) : runtime_error(msg)
        {}
    };

    // Klasa bledu wczytania pustego tekstu
    class EmptyTextException : public std::runtime_error
    {
    public:
        /*
        * Konstruktor
        */
        EmptyTextException() : runtime_error("Wczytany tekst jest pusty!")
        {}

        /*
        * Konstruktor
        * @param msg wiadomosc do bledu
        */
        EmptyTextException(std::string msg) : runtime_error(msg)
        {}
    };

    // Klasa bledu wczytania pustej mapy
    class EmptyCharacterMapException : public std::runtime_error
    {
    public:
        /*
        * Konstruktor
        */
        EmptyCharacterMapException() : runtime_error("Wczytana mapa znakow jest pusta!")
        {}

        /*
        * Konstruktor
        * @param msg wiadomosc do bledu
        */
        EmptyCharacterMapException(std::string msg) : runtime_error(msg)
        {}
    };

    // Klasa bledu zlej wartosci (w sensie logicznym) w mapie
    class BadValueInMapException : public std::runtime_error
    {
    public:
        /*
        * Konstruktor
        */
        BadValueInMapException() : runtime_error("Zla wartosc w mapie!")
        {}

        /*
        * Konstruktor
        * @param msg wiadomosc do bledu
        */
        BadValueInMapException(std::string msg) : runtime_error(msg)
        {}
    };
}

#endif