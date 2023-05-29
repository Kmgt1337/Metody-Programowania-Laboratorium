#include "Knapsack_backtracing.hpp"
#include "File.hpp"
#include <iostream>

int main()
{
    try
    {
        std::string path_in, path_out;
        std::cin >> path_in >> path_out;

        auto data = f_load_items_from_file(path_in.c_str());

        Knapsack_backtracing kb{data.first, data.second};
        kb.knapsack(0, 0, 0);

        f_save_to_file(path_out.c_str(), data.second, kb.give_nodes(), kb.give_reporer(), kb.best_value());
    }
    catch(const problem_with_file& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}