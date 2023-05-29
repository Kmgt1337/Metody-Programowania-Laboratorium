#include "File.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include "algorithm"
using namespace std;

vector<pair<int, int>> f_load_pairs_from_file(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        file.close();
        throw problem_with_file("Problem przy wczytywaniu par liczb z pliku");
    }

    vector<pair<int, int>> pairs;
    string line;

    while(getline(file, line))
    {
        istringstream ss(line);
        vector<int> temp;
        int num{};

        while(ss >> num)
        {
            temp.push_back(num);
        }

        pairs.push_back({temp.at(0), temp.at(1)});
    }

    sort(pairs.begin(), pairs.end(), 
    [](auto& lhs, auto& rhs)
    {
        return lhs.second < rhs.second;
    });

    file.close();
    return pairs;
}

void f_save_to_file(const char* path, const std::vector<int>& vec)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem przy zapisie do pliku");
    }

    for(const auto& e : vec)
    {
        file << e << endl;
    }

    file.close();
}