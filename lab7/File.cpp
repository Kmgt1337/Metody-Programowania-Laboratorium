#include "File.hpp"
#include <fstream>
using namespace std;

vector<C_data> f_read_data_from_file(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z odczytem z pliku");
    }
    
    vector<int> line;
    C_data single_data;
    vector<C_data> data;
    int num{};

    size_t data_count{};
    file >> data_count;

    for(size_t i = 0; i < data_count; i++)
    {
        single_data.matrix.clear();
        file >> single_data.rows >> single_data.cols;

        for(size_t j = 0; j < single_data.rows; j++)
        {
            line.clear();
            for(size_t k = 0; k < single_data.cols; k++)
            {
                file >> num;
                line.push_back(num);
            }
            single_data.matrix.push_back(line);
        }
        file >> single_data.key;
        data.push_back(single_data);
    }

    file.close();
    return data;
}

void f_save_results_to_file(const char* path, const std::vector<C_result>& results)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z zapisem do pliku");
    }

    for(const auto& e : results)
    {
        if(e.rec_low.first >= 0)
        {
            file << "RekPier: " << e.key << " w " << "(" << e.rec_low.first << "," << e.rec_low.second << ")" << endl; 
        }
        else
        {
            file << "RekPier: nie ma " << e.key << endl;
        }

        if(e.rec_high.first >= 0)
        {
            file << "RekOst: " << e.key << " w " << "(" << e.rec_high.first << "," << e.rec_high.second << ")" << endl; 
        }
        else
        {
            file << "RekOst: nie ma " << e.key << endl;
        }

        if(e.iter_low.first >= 0)
        {
            file << "IterPier: " << e.key << " w " << "(" << e.iter_low.first << "," << e.iter_low.second << ")" << endl; 
        }
        else
        {
            file << "IterPier: nie ma " << e.key << endl;
        }

        if(e.iter_high.first >= 0)
        {
            file << "IterOst: " << e.key << " w " << "(" << e.iter_high.first << "," << e.iter_high.second << ")" << endl; 
        }
        else
        {
            file << "IterOst: nie ma " << e.key << endl;
        }
        file << "---" << endl;
    }

    file.close();
}
