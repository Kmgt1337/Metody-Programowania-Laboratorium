#include "File.hpp"
#include "MyExceptions.hpp"
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

string f_read_text_from_file(string path)
{
    ifstream file(path.c_str());
    if(!file.good())
    {
        throw myexceptions::FileOpenException("Nie mozna otworzyc pliku " + path);
    }

    std::string line;
    std::string text;

    while(getline(file, line))
    {
        text += line + "\n";
    }

    text.pop_back();

    file.close();
    return text;
}

unordered_map<char, float> f_read_chars_from_file(string path)
{
    ifstream file(path);
    if(!file.good())
    {
        throw myexceptions::FileOpenException("Nie mozna otworzyc pliku " + path);
    }

    unordered_map<char, float> map;
    char ch;
    float num;

    while(file >> ch >> num)
    {
        map[ch] = num;
    }

    file.close();
    return map;
}

void f_save_results_to_file(std::string path, Huffman_coding huffman)
{
    ofstream file(path.c_str());
    if(!file.good())
    {
        throw myexceptions::FileOpenException("Nie mozna otworzyc pliku " + path);
    }

    auto codes = huffman.huffman_codes();
    file << "Kody:\n";

    for(const auto& e : codes)
    {
        if(e.first == '\n')
        {
            file << "\\n " << e.second << endl; 
        }
        else
        {
            file << e.first << " " << e.second << endl;
        }
    }

    file << "\nTekst:\n";
    file << huffman.decoded_text() << endl;

    file << "\nZakodowany tekst:\n";
    file << huffman.encoded_text() << endl;

    file.close();
}