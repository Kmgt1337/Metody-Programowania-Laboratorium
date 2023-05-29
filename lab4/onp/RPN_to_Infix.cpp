#include "RPN_to_Infix.hpp"
#include "Auxiliary.hpp"
#include <stack>
#include <iostream>
using namespace std;

int f_precedence(string alpha)
{
    if(alpha == "=")
    {
        return 0;
    }

    if(alpha == "<" || alpha == ">")
    {
        return 1;
    }

    if(alpha == "+" || alpha == "-")
    {
        return 2;
    }
 
    if(alpha == "*" || alpha == "/" || alpha == "%")
    {
        return 3;
    }
 
    if(alpha == "^")
    {
        return 4;
    }

    if(alpha == "~")
    {
        return 5;
    }

    if(alpha >= "a" && alpha <= "z")
    {
        return 6;
    }

    return 0;
}

string f_rpn_to_infix(string input)
{
    stack<string> stos;
    stack<int> precedence_stack;
    string tmp = "";
    int num_of_operands = 0, num_of_operators = 0;

    string s = f_delete_white_spaces_and_wrong_chars(input);
    std::vector<std::string> rpn = f_convert_string_to_vector(s);

    for(std::size_t i = 0; i < rpn.size(); i++)
    {
        if(!(rpn.at(i) == "(") && !(rpn.at(i) == ")"))
        {
            if(rpn.at(i).at(0) >= 'a' && rpn.at(i).at(0) <= 'z')
            {
                stos.push(rpn.at(i));
                precedence_stack.push(f_precedence(rpn.at(i)));
                num_of_operands++;
            }
            else
            {
                tmp = "";
                if(!(rpn.at(i) == "~"))
                {
                    if(!precedence_stack.size() || !stos.size())
                    {
                        return "error";
                    }
                    num_of_operators++;

                    if(precedence_stack.top() <= f_precedence(rpn.at(i)))
                    {
                        string temp = stos.top();
                        stos.pop();
                        tmp = "(" + temp + ")";
                    }
                    else
                    {
                        string temp = stos.top();
                        stos.pop();
                        tmp = temp;
                    }

                    if(!precedence_stack.size() || !stos.size())
                    {
                        return "error";
                    }
                    precedence_stack.pop();

                    if(precedence_stack.top() < f_precedence(rpn.at(i)))
                    {
                         string temp = stos.top();
                         stos.pop();
                         tmp = "(" + temp + ")" + rpn.at(i) + tmp;
                    }
                    else
                    {
                        string temp = stos.top();
                        stos.pop();
                        tmp = temp + rpn.at(i) + tmp;
                    }

                    if(!precedence_stack.size())
                    {
                        return "error";
                    }

                    precedence_stack.pop();
                }
                else
                {
                    if(!precedence_stack.size() || !stos.size())
                    {
                        return "error";
                    }

                    if(precedence_stack.top() <= f_precedence(rpn.at(i)))
                    {
                        string temp = stos.top();
                        stos.pop();
                        tmp = rpn.at(i) + "(" + temp + ")";
                    }
                    else
                    {
                        string temp = stos.top();
                        stos.pop();
                        tmp = rpn.at(i) + temp;
                    }

                    if(!precedence_stack.size())
                    {
                        return "error";
                    }
                    precedence_stack.pop();
                }
                stos.push(tmp);
                precedence_stack.push(f_precedence(rpn.at(i)));
            }
        }
    }

    if(num_of_operands - 1 == num_of_operators)
    {
        return stos.top();
    }

    return "error";
}