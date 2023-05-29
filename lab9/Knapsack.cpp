#include "Knapsack.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> f_knapsack_dynamic(const vector<item>& items, int capacity)
{
    vector<vector<int>> P(items.size() + 1, vector<int>(capacity + 1));
    vector<vector<int>> Q(items.size() + 1, vector<int>(capacity + 1));

    for(int j = 0; j <= capacity; j++)
    {
        P.at(0).at(j) = 0;
        Q.at(0).at(j) = 0;
    }
    
    for(int i = 0; i <= items.size(); i++)
    {
        P.at(i).at(0) = 0;
        Q.at(i).at(0) = 0;
    }

    for(int i = 1; i <= items.size(); i++)
    {
        for(int j = 1; j <= capacity; j++)
        {            
            if(items.at(i - 1).get_weight() > j)
            {
                P.at(i).at(j) = P.at(i - 1).at(j);
                Q.at(i).at(j) = Q.at(i - 1).at(j);
            }
            else
            {
                int val1 = P.at(i - 1).at(j);
                int val2 = P.at(i).at(j - items.at(i - 1).get_weight()) + items.at(i - 1).get_value();

                if(val1 > val2)
                {
                    P.at(i).at(j) = val1;
                    Q.at(i).at(j) = Q.at(i - 1).at(j);
                }
                else
                {
                    P.at(i).at(j) = val2;
                    Q.at(i).at(j) = i;
                }
            }
        }
    }
    return {P, Q};
}

vector<item> f_all_items_added_to_knapsack(const vector<item>& items, const vector<vector<int>>& Q)
{
    vector<item> items_added;

    int current_item = Q.size() - 1;
    int current_weight = Q.at(0).size() - 1;

    while(current_item > 0 && current_weight > 0)
    {
        if(Q.at(current_item).at(current_weight) - 1 <= 0) 
        {
            break;
        }
        items_added.push_back(items.at(Q.at(current_item).at(current_weight) - 1));
        current_weight -= items.at(Q.at(current_item).at(current_weight) - 1).get_weight();        
    }

    reverse(items_added.begin(), items_added.end());

    return items_added;
}

int f_get_maximum_value(const vector<vector<int>>& P)
{
    if(!P.size())
    {
        return -1;
    }

    return P.at(P.size() - 1).at(P.at(P.size() - 1).size() - 1);
}

bool f_knapsack_rec(const std::vector<int>& items, std::vector<int>& items_fit_knapsack, const int& capacity, int pick)
{
    if(pick == items.size()) 
    {
        cout << "BRAK" << endl;
        return false;
    }

    if(items.at(pick) < capacity) 
    {   
        cout << items.at(pick) << ", waga docelowa: " << capacity << ". " << items.at(pick) << " to za malo" << endl;
            
        if(!f_knapsack_rec(items, items_fit_knapsack, capacity - items.at(pick), pick + 1))
        {
            return f_knapsack_rec(items, items_fit_knapsack, capacity, pick + 1);
        }
        else
        {
            items_fit_knapsack.push_back(items.at(pick));
            return true; 
        }
    } 
    else if (items.at(pick) > capacity) 
    {
        cout << items.at(pick) << ", waga docelowa: " << capacity << ". " << items.at(pick) << " to za duzo" << endl;
        return f_knapsack_rec(items, items_fit_knapsack, capacity, pick+1);
    } 
    else 
    {
        cout << items.at(pick) << ", waga docelowa: " << capacity << ". " << items.at(pick) << ". Pasuje. Koniec" << endl;
        items_fit_knapsack.push_back(items.at(pick));
        return true;
    }
}