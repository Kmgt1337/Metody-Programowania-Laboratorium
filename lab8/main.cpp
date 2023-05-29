#include "LCG_gen.hpp"
#include "ACG_gen.hpp"
#include "File.hpp"
#include "Auxiliary.hpp"
#include <iostream>

int main()
{
    std::cout << "[1] - generator LCG\n";
    std::cout << "[2] - generator ACG\n";
    std::cout << "Wybierz opcje: ";
    int option;
    std::cin >> option;

    switch(option)
    {
        case 1:
        {
            int x_min{}, x_max{}, seed{}, n{};

            std::cout << "Podaj minimalny zakres: ";
            x_min = f_load_number(0);

            std::cout << "Podaj maksymalny zakres: ";
            x_max = f_load_number(x_min);

            std::cout << "Podaj seed: ";
            seed = f_load_number(0, x_max);

            std::cout << "Podaj ile liczb wylosowac: ";
            n = f_load_number(0);

            std::vector<int> vec;
            LCG_gen lcg{x_min, x_max, seed};

            for(int i = 0; i < n; i++)
            {
                vec.push_back(lcg.rand());
                std::cout << vec.at(i) << " ";
            }

            std::cout << "\n\nPodaj sciezke do zapisu wynikow: ";
            std::string path;
            std::cin >> path;

            try
            {
                f_save_to_file(path.c_str(), vec);
            }
            catch(const problem_with_file& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(...)
            {
                std::cerr << "Nieznany blad" << std::endl;
            }
            
            break;
        }

        case 2:
        {
            try
            {
                int n{}, m{}, count{};
                std::string path;

                std::cout << "Podaj n: ";
                n = f_load_number(1);

                std::cout << "Podaj m: ";
                m = f_load_number(1);

                std::cout << "Podaj ile liczb wylosowac: ";
                count = f_load_number(0);

                std::cout << "Podaj sciezke do pliku z parami liczb: ";
                std::cin >> path;

                std::vector<int> vec;
                ACG_gen::init(path.c_str());
                ACG_gen acg{n, m};

                for(int i = 0; i < count; i++)
                {
                    vec.push_back(acg.rand());
                    std::cout << vec.at(i) << " ";
                }

                std::cout << "\n\nPodaj sciezke do zapisu wynikow: ";
                std::cin >> path;

                f_save_to_file(path.c_str(), vec);
            }
            catch(const problem_with_file& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(const no_pair_found& e)
            {
                std::cerr << e.what() << "\n";
            }
            catch(...)
            {
                std::cerr << "Nieznany blad" << std::endl;
            }
    
            break;
        }
    }
}