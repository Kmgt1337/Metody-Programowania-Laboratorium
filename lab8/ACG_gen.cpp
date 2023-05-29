#include "ACG_gen.hpp"
#include "LCG_gen.hpp"
#include "File.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

std::vector<std::pair<int, int>> ACG_gen::_pairs;

ACG_gen::ACG_gen(int n, int m)
{
    _n = n;
    _m = m;
    auto p = choose_best_pair(_pairs);
    _j = p.first;
    _k = p.second;

    LCG_gen gen{1, max(m, n), max(m, n) / 2};
    vector<int> X;
    X.push_back(0);

    for(int i = 0; i < _n; i++)
    {
        X.push_back(gen.rand());
    }

    _Y.push_back(0);
    for(size_t i = X.size() - 1; i > 0; i--)
    {
        _Y.push_back(X.at(i));
    }
}

int ACG_gen::rand()
{
    _Y.at(_k) = (_Y.at(_j) + _Y.at(_k)) % _m;
    int x = _Y.at(_k);

    --_k;
    --_j;

    if(_j == 0) _j = _n;
    else if(_k == 0) _k = _n;

    return x;
}

void ACG_gen::init(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        file.close();
        throw problem_with_file("Problem przy wczytywaniu par liczb z pliku");
    }

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

        _pairs.push_back({temp.at(0), temp.at(1)});
    }

    sort(_pairs.begin(), _pairs.end(), 
    [](auto& lhs, auto& rhs)
    {
        return lhs.second < rhs.second;
    });

    file.close();
}

std::pair<int, int> ACG_gen::choose_best_pair(const std::vector<std::pair<int, int>>& pairs)
{
    vector<pair<int, int>> pairs_temp;
    for(size_t i = 0; i < pairs.size(); i++)
    {
        if(pairs.at(i).first < _n && pairs.at(i).second < _n)
        {
            pairs_temp.push_back(pairs.at(i));
        }
    }

    if(!pairs_temp.size())
    {
        throw no_pair_found("Nie znaleziono pary dla podanych n oraz m");
    }

    auto max_second = *max_element(pairs_temp.begin(), pairs_temp.end(), 
    [](const auto& lhs, const auto& rhs)
    {
        return lhs.second < rhs.second;
    });

    vector<pair<int, int>> pairs_temp_second;
    for(size_t i = 0; i < pairs_temp.size(); i++)
    {
        if(max_second.second == pairs_temp.at(i).second)
        {
            pairs_temp_second.push_back(pairs_temp.at(i));
        }
    }

    auto max_first = *max_element(pairs_temp_second.begin(), pairs_temp_second.end(), 
    [](const auto& lhs, const auto& rhs)
    {
        return lhs.first < rhs.first;
    });

    return {max_first.first, max_first.second};
}