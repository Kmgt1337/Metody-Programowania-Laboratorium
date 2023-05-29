#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <queue>

// Klasa reprezentujaca wierzcholek w drzewie Huffmana
struct Node
{
    // znak w wierzcholku
    char _ch;

    // czestotliwosc wystepowania znaku
    int _freq;

    // prawdopodobienstwo wystapienia znaku
    double _prob;

    // wskaznik do lewego dziecka
    Node* _left;

    // wskaznik do prawego dziecka
    Node* _right;
};

/*
* Funkcja do tworzenia nowego wierzcholka w drzewie Huffmana
* @param ch znak wystepujacy w wierzcholku
* @param freq czestotliwosc wystepowania znaku
* @param prob prawdopodobienstwo wystapienia znaku
* @param left wskaznik do lewego dziecka
* @param right wskaznik do prawego dziecka
* @returns wskaznik do nowo utworzonego wierzcholka
*/
Node* f_create_new_node(char ch, int freq, double prob, Node* left, Node* right);

// Klasa sluzaca do przeprowadzenia kodowania Huffmana
class Huffman_coding
{
public:
    // Typ wyliczeniowy do okreslenia trybu dzialania klasy
    enum class OPERATING_MODE
    {
        // tryb tekstowy (gdy wczytujemy caly tekst do zakodowania)
        TEXT_MODE,

        // tryb czestotliwosciowy (gdy wczytujemy znaki i ich czestotliwosci)
        FREQ_MODE,

        // tryb prawdopodobienstw (gdy wczytujemy znaki i ich prwadopodobienstwa)
        PROB_MODE
    };

    /*
    * Konstruktor
    * @param txt tekst do zakodowania
    */
    Huffman_coding(std::string txt);

    /*
    * Konstruktor
    * @param char_map std::unordered_map<char, float> mapa znakow
    * @param mode tryb pracy
    */
    Huffman_coding(const std::unordered_map<char, float>& char_map, OPERATING_MODE mode);
    
    /*
    * Funkcja ktora zwraca kody Huffmana
    * @returns kody Huffmana
    */
    std::unordered_map<char, std::string> huffman_codes() 
    {
        return _huffman_codes;
    }

    /*
    * Funkcja ktora zwraca zakodowany tekst
    * @returns zakodowany tekst
    */
    std::string encoded_text()
    {
        return _encoded_text;
    }

    /*
    * Funkcja ktora zwraca zdekodowany tekst
    * @returns zdekodowany tekst
    */
    std::string decoded_text()
    {
        return _decoded_text;
    }

private:
    /*
    * Funkcja ktora tworzy drzewo Huffmana (wykonuje wlasciwy algorytm Huffmana)
    */
    void make_huffman_tree();

    /*
    * Funkcja ktora tworzy kody Huffmana na podstawie drzewa Huffmana (przeszukuje drzewo Huffmana)
    * @param root wskaznik do korzenia drzewa
    * @param txt pomocniczy napis
    */
    void create_huffman_codes(Node* root, std::string txt);

    /*
    * Funkcja ktora zakodowuje tekst na podstawie kodow Huffmana
    * @param txt tekst do zakodowania
    * @returns zakodowany tekst
    */
    std::string encode_text(std::string txt);

    /*
    * Funkcja ktora dekoduje tekst na podstawie kodow Huffmana
    * @param txt tekst do zdekodowania
    * @returns zdekodowany tekst
    */
    std::string decode_text(std::string txt);

    // tryb pracy
    OPERATING_MODE _mode;

    // wskaznik do korzenia drzewa Huffmana
    Node* _root;

    // tekst na ktorym klasa pracuje (tylko w trybie tekstowym)
    std::string _txt;

    // zakodowany tekst (tylko w trybie tekstowym)
    std::string _encoded_text;

    // zdekodowany tekst (tylko w trybie tekstowym)
    std::string _decoded_text;

    // mapa znakow i ich czestotliwosci lub prawdopodobienstw
    std::unordered_map<char, float> _char_map;

    // kody Huffmana (jako mapa char i string)
    std::unordered_map<char, std::string> _huffman_codes;

    // komparator do porownywania czestotliwosci lub prawdopodobienstw w algorytmie Huffmana
    std::function<bool(const Node*, const Node*)> _comp;

    /*
    * Funkcja ktora ustawa komparator w zaleznosci od trybu
    */
    void set_comparator();

    /*
    * Funkcja ktora ustawia kolejke priorytetowa potrzebna do dzialania algorytmu Huffmana
    * @param pq kolejka priorytetowa
    */
    void set_priority_queue(std::priority_queue<Node*, std::vector<Node*>, decltype(_comp)>& pq);

    /*
    * Funkcja ktora sprawdza poprawnosc wczytanych danych w trybie czestotliwosci
    */
    void check_freq_mode_map();

    /*
    * Funkcja ktora sprawdza poprawnosc wczytanych danych w trybie prawdopodobienstw
    */
    void check_prob_mode_map();
};

#endif