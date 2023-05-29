#include "Auxiliary.hpp"
#include "Infix_to_RPN.hpp"
#include <cctype>
#include <iostream>

std::string f_delete_white_spaces_and_wrong_chars(std::string input)
{
    std::string infix;
    for(std::size_t i = 0; i < input.size(); i++)
    {
        if(!isspace(input.at(i)) && (isalpha(input.at(i)) || f_is_oper(input.at(i)) || f_is_parenthesis(input.at(i))))
        {
            infix += input.at(i);
        }
    }

    return infix;
}

std::vector<std::string> f_convert_string_to_vector(std::string input)
{
    std::vector<std::string> vec;
    
    for(std::size_t i = 0; i < input.size(); i++)
    {
        vec.push_back(std::string(1, input.at(i)));
    }

    return vec;
}