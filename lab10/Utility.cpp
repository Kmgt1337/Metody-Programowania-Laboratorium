#include "Utility.hpp"

int calculate_position(int level, const std::vector<Node>& nodes)
{
    return count_if(nodes.begin(), nodes.end(), 
    [=](const Node& v)
    {
        return v.get_level() == level;
    });
}