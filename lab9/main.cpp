#include "Knapsack.hpp"
#include "File.hpp"
#include <iostream>

int main()
{
    try
    {
        std::string path_in, path_out;
        std::cin >> path_in >> path_out;

        auto data = f_load_items_from_file(path_in.c_str());
        auto items = data.second;
        auto capacity = data.first;

        auto result = f_knapsack_dynamic(items, capacity);
        auto P = result.first;
        auto Q = result.second;

        auto all_items_in_knapsack = f_all_items_added_to_knapsack(items, Q);
        auto max_value = f_get_maximum_value(P);

        f_save_dynamic_to_file(path_out.c_str(), P, Q, all_items_in_knapsack, max_value);
        std::cout << "Zapisano wyniki dla algorytmu dynamicznego\n";

        std::cin >> path_in >> path_out;

        auto rec_data = f_load_weights_from_file(path_in.c_str());
        std::vector<data_set> results_rec;
        std::vector<int> weights_fit;

        for(int i = 0; i < rec_data.size(); i++)
        {
            weights_fit.clear();
            auto weights = rec_data.at(i).get_weights();

            std::cout << "===========================\n";
            bool can_be_filled = f_knapsack_rec(weights, weights_fit, rec_data.at(i).get_capacity(), 0);
            std::cout << "===========================\n";
            
            reverse_vec(weights_fit);
            results_rec.push_back(data_set{rec_data.at(i).get_capacity(), weights_fit, can_be_filled});
        }

        f_save_rec_to_file(path_out.c_str(), results_rec);
        std::cout << "\nZapisano wyniki dla algorytmu rekurencyjnego";
    }
    catch(const problem_with_file& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cerr << "Nieznany blad" << "\n";
        return 1;
    }
}