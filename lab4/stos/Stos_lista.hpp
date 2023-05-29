#ifndef STOS_LISTA_HPP
#define STOS_LISTA_HPP

#include <stdexcept>

// Szablon reprezentujacy pojedynczy wezel listy
template<typename T>
class Wezel
{
public:
    // element tablicy
    T _elem;

    // wskaznik do nastepnego wezla listy
    Wezel* _nastepny;

    /*
    * Konstruktor
    * @param elem element 
    */
    Wezel(T elem);
};

template<typename T>
Wezel<T>::Wezel(T elem)
{
    _elem = elem;
    _nastepny = nullptr;
}

// Szablon stosu opartego na liscie jednokierunkowej
template<typename T>
class Stos_lista
{
private:
    // wskaznik na gore stosu
    Wezel<T>* _gora;

    // liczba elementow na stosie
    int _n;

public:
    // Konstruktor
    Stos_lista();

    // Destruktor
    ~Stos_lista();

    /*
    * Funkcja skladowa dodajaca na wierzcholek stosu nowy element
    * @param elem element do dodania
    */
    void dodaj(T elem);

    // Funkcja skladowa usuwajaca element z wierzcholka stosu
    void usun();

    /*
    * Funkcja skladowa zwracajaca element szczytowy ze stosu
    * @returns element szczytowy 
    */
    T element_szczytowy();

    /*
    * Funkcja skladowa sprawdzajaca czy stos jest pusty
    * @returns true jesli stos jest pusty, false jesli posiada elementy
    */
    bool czy_jest_pusty();

    /*
    * Funkcja zwracajaca rozmiar stosu
    * @returns rozmiar stosu
    */
    int rozmiar();
};

template<typename T>
Stos_lista<T>::Stos_lista()
{
    _n = 0;
    _gora = nullptr;
}

template<typename T>
Stos_lista<T>::~Stos_lista()
{
    Wezel<T>* temp = _gora;
    while(temp)
    {
        _gora = _gora->_nastepny;
        delete temp;
        temp = _gora;
    }
}

template<typename T>
void Stos_lista<T>::dodaj(T elem)
{
    Wezel<T>* temp = new Wezel<T>(elem);

    if(!temp)
    {
        throw std::overflow_error("Overflow error");
    }

    temp->_elem = elem;
    temp->_nastepny = _gora;
    _gora = temp;
    _n++;
}

template<typename T>
void Stos_lista<T>::usun()
{
    Wezel<T>* temp;

    if(!_gora)
    {
        throw std::underflow_error("Underflow error");
    }

    temp = _gora;
    _gora = _gora->_nastepny;
    _n--;
    
    delete temp;
}

template<typename T>
T Stos_lista<T>::element_szczytowy()
{
    if(czy_jest_pusty())
    {
        throw std::underflow_error("Underflow error");
    }
    return _gora->_elem;
}

template<typename T>
bool Stos_lista<T>::czy_jest_pusty()
{
    return _gora == nullptr;
}

template<typename T>
int Stos_lista<T>::rozmiar()
{
    return _n;
}

#endif