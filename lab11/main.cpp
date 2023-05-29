#include "Huffman.hpp"
#include "File.hpp"
#include <iostream>

int main()
{
    try
    {
        char option;
        std::cout << "Podaj tryb dzialania programu:\n";
        std::cout << "Wczytanie tekstu (t)\n";
        std::cout << "Wczytanie znakow oraz ich czestotliwosci (c)\n";
        std::cout << "Wczytanie znakow oraz ich prawdopodobienstwa (p)\n";
        std::cout << "Podaj wybor: ";
        std::cin >> option;
        option = tolower(option);

        std::string path_in, path_out;

        switch (option)
        {
            case 't':
            {
                std::cin >> path_in >> path_out;
                Huffman_coding huffman{f_read_text_from_file(path_in)};

                f_save_results_to_file(path_out, huffman);
                std::cout << "Zapisano wyniki do pliku " << path_out << std::endl;

                break;
            }

            case 'c':
            {
                std::cin >> path_in >> path_out;
                Huffman_coding huffman{f_read_chars_from_file(path_in), Huffman_coding::OPERATING_MODE::FREQ_MODE};

                f_save_results_to_file(path_out, huffman);
                std::cout << "Zapisano wyniki do pliku " << path_out << std::endl;

                break;
            }

            case 'p':
            {
                std::cin >> path_in >> path_out;
                Huffman_coding huffman{f_read_chars_from_file(path_in), Huffman_coding::OPERATING_MODE::PROB_MODE};

                f_save_results_to_file(path_out, huffman);
                std::cout << "Zapisano wyniki do pliku " << path_out << std::endl;
                break;
            }

            default:
            {
                std::cout << "Zla opcja!\n";
                break;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cin.ignore();
    std::cin.get();
}