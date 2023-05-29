#ifndef LIST_HPP
#define LIST_HPP
#include <string>

// Klasa reprezentujaca pojedynczy wezel w liscie jednokierunkowej
class C_node 
{
public:
    // dana przechowywana przez wezel
    int _data;

    // wskaznik do nastepnego wezla 
    C_node* _next;

    /*
    * Konstruktor klasy
    * @param val dana przechowywana przez wezel
    */
    C_node(int val = 0) : _data(val), _next(nullptr)
    {}
};

// Klasa reprezentujaca liste jednokierunkowa
class C_linked_list
{
public:
    // Konstruktor klasy
    C_linked_list();

    /*
    * Funkcja skladowa sluzaca do stworzenia nowego wezla i dodaniu go do listy
    * @param data wartosc do dodania do listy
    */
    void push_back(int data);

    /*
    * Funkcja skladowa przechodzaca po liscie i zwracajaca w formie napisu wszystkie wartosci elementow
    * @returns napis zawierajacy wszystkie elementy listy
    */
    std::string str() const;

    /*
    * Funkcja skladowa zwracajaca rozmiar listy
    * @returns rozmiar listy
    */
    int size() const;

private:
    // Wskaznik na glowe listy
    C_node* _head;
};

#endif