#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "File.hpp"
#include "Infix_to_RPN.hpp"
#include "RPN_to_Infix.hpp"

int main()
{
    std::vector<std::string> infix_inputs;
    std::vector<std::string> rpn_inputs;

    std::vector<std::pair<std::string, std::string>> inputs;
    std::vector<std::pair<std::string, std::string>> outputs;

    if(!f_read_from_file("in.txt", inputs))
    {
        return -1;
    }

    for(const auto& e : inputs)
    {
        if(e.first == "INF")
        {
            outputs.push_back(std::make_pair(std::string("ONP"), f_infix_to_rpn(e.second)));
        }
        else if(e.first == "ONP")
        {   
            outputs.push_back(std::make_pair(std::string("INF"), f_rpn_to_infix(e.second)));
        }
    }

    if(!f_save_to_file("out.txt", outputs))
    {
        return -1;
    }
}