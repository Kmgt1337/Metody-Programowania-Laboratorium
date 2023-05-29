#include "File.hpp"
#include <fstream>
#include <sstream>

using namespace std;

pair<int, vector<Item>> f_load_items_from_file(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z odczytem pliku");
    }

    string line;
    vector<Item> items;
    int W{}, value{}, weight{};

    getline(file, line);
    W = stoi(line);

    while(getline(file, line))
    {
        istringstream iss(line);
        iss >> value;
        iss >> weight;

        items.push_back(Item{value, weight});
    }

    file.close();
    return {W, items};
}

void f_save_to_file(const char* path, const std::vector<Item>& items, const std::vector<Node>& nodes, const Reporter& rep, int mp)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z zapisem do pliku");
    }

    auto sorted_items = items;
    sort(sorted_items.begin(), sorted_items.end(),
    [](const Item& a, const Item& b)
    {
        return a.get_ratio() > b.get_ratio();
    });

    file << "Przedmioty:\n";
    for(const auto& e : sorted_items)
    {
        file << "p = " << e.get_value() << ", w =  " << e.get_weight() << ", p/w = " << e.get_ratio() << endl;
    }

    file << "\nPrzebieg algorytmu:\n";
    file << rep.give_message() << endl;
    file << "KONIEC ALGORYTMU\n\n";

    file << "Odwiedzone wierzcholki:\n";
    for(const auto& e : nodes)
    {
        file << "(" << e.get_level() << "," << e.get_location() << ")" << ", p = " << e.get_profit() << ", w = " << e.get_weight() << ", b = " << e.get_bound() << ", mp = " << e.get_mp() << endl;
    }

    file << "\nNajwiekszy zysk = " << mp << endl;

    file.close();
}