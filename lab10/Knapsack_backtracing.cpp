#include "Knapsack_backtracing.hpp"
#include <algorithm>

using namespace std;

Knapsack_backtracing::Knapsack_backtracing(int W, const vector<Item>& items)
{
    _mp = 0;
    _W = W;
    _items = items;

    sort(_items.begin(), _items.end(),
    [](const Item& a, const Item& b)
    {
        return a.get_ratio() > b.get_ratio();
    });
}

int Knapsack_backtracing::calculate_bound(int level_index, int profit, int weight)
{
    int i = level_index;
    int k = -1;
    int sum_of_current_weights = 0;

    for(size_t i = 0; i < _items.size(); i++)
    {
        if(_items.at(i).is_online())
        {
            sum_of_current_weights += _items.at(i).get_weight();
            if(sum_of_current_weights >= _W)
            {
                k = i + 1;
                break;
            }
        }
    }

    if(k == -1)
    {
        k = _items.size() + 1;
    }

    int totweight = weight;
    for(int j = i + 1; j <= k - 1; j++)
    {
        totweight += _items.at(j - 1).get_weight();
    }
    _rep.report("\tSprawdzamy teraz zalozenia z bound:");
    _rep.report("\n\ttotweight = " + to_string(totweight) + "\n");

    int sum_value = 0;
    _rep.report("\ti = " + to_string(i) + ", \tk = " + to_string(k) + "\n");
    for(size_t j = i + 1; j <= k - 1; j++)
    {   
        sum_value += _items.at(j - 1).get_value();
    }

    int bound = 0;
    if(k <= _items.size())
    {
        bound = (profit + sum_value) + (_W - totweight) * _items.at(k - 1).get_ratio();
    }
    else
    {
        bound = (profit + sum_value);
    }

    _rep.report("\tb = " + to_string(bound) + "\n");

    return bound;
}

bool Knapsack_backtracing::promising(int bound)
{
    _rep.report("\tSprawdzamy czy: bound > mp, czyli: " + to_string(bound) + " > " + to_string(_mp) + "\n");
    if(bound > _mp)
    {
        _rep.report("\tTAK wiec idziemy w wezel po lewej\n");
    }
    else
    {
        _rep.report("\t\tNIE wiec wezel jest NIEOBIECUJACY. Cofamy sie do rodzica i idziemy w prawo\n");
    }
    return bound > _mp;
}

void Knapsack_backtracing::knapsack(int level_index, int profit, int weight)
 {
    string pos;
    if(level_index == 0)
    {
        pos = to_string(calculate_position(level_index, _nodes));
    }
    else
    {
        pos = to_string(calculate_position(level_index, _nodes) + 1);
    }

    _rep.report("\nWezel(" + to_string(level_index) + ", " + pos
    + "):\n\tobecna waga = " + to_string(weight) + ", obecny zysk = " + to_string(profit) + "\n");
    _rep.report("\tsprawdzamy czy: obecna waga >= W, czyli: " + to_string(weight) + " >= " + to_string(_W));

    if(weight >= _W + 1) 
    {
        Node v{level_index, calculate_position(level_index, _nodes) + 1, profit , weight, 0, _mp};
        _nodes.push_back(v);
        _rep.report("\n\t\tTAK wiec wezel jest NIEOBIECUJACY. Cofamy sie do rodzica i idziemy w prawo\n");
        return;
    }

    if(profit > _mp)
    {
        _mp = profit;
    }

    _rep.report("\n\tNIE wiec idziemy dalej\n");
    _rep.report("\tmax_profit = " + to_string(_mp) + "\n");

    int bound = calculate_bound(level_index, profit, weight);

    if(level_index == 0)
    {
        Node v{level_index, calculate_position(level_index, _nodes), profit , weight, bound, _mp};
        _nodes.push_back(v);
    }
    else
    {
        Node v{level_index, calculate_position(level_index, _nodes) + 1, profit , weight, bound, _mp};
        _nodes.push_back(v);
    }

    if(promising(bound))
    {
        _items.at(level_index).change_state_to(true);
        knapsack(level_index + 1, profit + _items.at(level_index).get_value(), weight + _items.at(level_index).get_weight());

        _items.at(level_index).change_state_to(false);
        knapsack(level_index + 1, profit, weight);
        _items.at(level_index).change_state_to(true);
    }
}