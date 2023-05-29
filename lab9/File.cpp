#include "File.hpp"
#include <fstream>  
#include <sstream>
#include <string>
using namespace std;

pair<int, vector<item>> f_load_items_from_file(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z wczytywaniem pliku z przedmiotami");
    }

    vector<item> items;
    string name, line;
    int cost, weight, capacity;

    getline(file, line);
    capacity = stoi(line);

    while(getline(file, line))
    {  
        istringstream iss(line);
        iss >> name; 
        iss >> weight;
        iss >> cost; 

        items.push_back(item{cost, weight, name});
    }

    file.close();
    return {capacity, items};
}

void f_save_dynamic_to_file(const char* path, const std::vector<std::vector<int>>& P, const std::vector<std::vector<int>>& Q, const std::vector<item>& items, int max_value)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z zapisem pliku z wynikami dla dynamicznego");
    }

    for(const auto& e : P)
    {
        for(const auto& f : e)
        {
            file << f << "\t\t";
        }
        file << endl;
    }

    file << endl;
    for(const auto& e : Q)
    {
        for(const auto& f : e)
        {
            file << f << "\t\t";
        }
        file << endl;
    }

    file << "\nPrzedmioty:";
    
    for(const auto& e : items)
    {
        file << e.get_name() << " ";
    }

    file <<"\nMaksmyalna wartosc = " << max_value << endl;

    file.close();
}

vector<data_set> f_load_weights_from_file(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z wczytywaniem pliku z wagami");
    }

    vector<data_set> data;

    int count;
    file >> count;

    for(int i = 0; i < count; i++)
    {
        int capacity;
        file >> capacity;
        
        int num_count;
        file >> num_count;

        vector<int> weights;
        for(int i = 0; i < num_count; i++)
        {
            int num;
            file >> num;
            weights.push_back(num);
        }

        data.push_back(data_set{capacity, weights, false});
    }

    return data;
}

void f_save_rec_to_file(const char* path, const std::vector<data_set>& data)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z zapisanem pliku z wagami");
    }

    for(const auto& e : data)
    {
        if(e.is_filled())
        {
            file << e.get_capacity() << " = ";
            for(const auto& j : e.get_weights())
            {
                file<< j << " ";
            }
        }
        else
        {
            file << "BRAK";
        }
        file << endl;
    }

    file.close();
}