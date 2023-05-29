#include <iostream>
#include "File.hpp"
#include "Algorithm.hpp"
#include "Auxiliary.hpp"
using namespace std;

int main()
{
    try
    {   
        string path_in, path_out;
        cin >> path_in >> path_out;
        auto data = f_read_data_from_file(path_in.c_str());

        vector<C_result> results;
        C_result result;

        for(size_t i = 0; i < data.size(); i++)
        {
            result.iter_low = f_search_first_occuerence_iter(data.at(i).matrix, data.at(i).key);
            result.iter_high = f_search_last_occuerence_iter(data.at(i).matrix, data.at(i).key);
            result.rec_low = f_search_first_occuerence_rec(data.at(i).matrix, data.at(i).key);
            result.rec_high = f_search_last_occuerence_rec(data.at(i).matrix, data.at(i).key);

            result.key = data.at(i).key;

            results.push_back(result);
        }

        f_save_results_to_file(path_out.c_str(), results);
    }
    catch(const problem_with_file& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    catch(const std::out_of_range& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    catch(...)
    {
        cerr << "Nieznany blad" << endl;
        return -1;
    }
}
