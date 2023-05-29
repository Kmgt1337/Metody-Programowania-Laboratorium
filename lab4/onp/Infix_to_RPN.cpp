#include "Infix_to_RPN.hpp"
#include "Auxiliary.hpp"
#include <stack>
using namespace std;

bool f_check_if_infix_is_valid(std::string input)
{
    if(!input.size())
    {
        return false;
    }

    if(f_is_double_oper(input.at(0)) || input.at(0) == ')')
    {
        return false;
    }

    for(size_t i = 1; i < input.size() - 1; i++)
    {
        if((f_is_double_oper(input.at(i)) && f_is_double_oper(input.at(i - 1))) || 
        (f_is_double_oper(input.at(i)) && f_is_double_oper(input.at(i + 1))))
        {
            return false;
        }

        if((isalpha(input.at(i)) && isalpha(input.at(i - 1)))
        || (isalpha(input.at(i)) && isalpha(input.at(i + 1))))
        {
            return false;
        }

        if( (input.at(i) == '(' && input.at(i - 1) == ')') ||
            (input.at(i) == '(' && input.at(i + 1) == ')') ||
            (input.at(i) == ')' && input.at(i - 1) == '(') ||
            (input.at(i) == ')' && input.at(i + 1) == '('))
        {
            return false;
        }
    }

    if(input.at(input.size() - 1) == '(' || f_is_double_oper(input.at(input.size() - 1)))
    {
        return false;
    }

    return true;
}

bool f_is_double_oper(char alpha)
{
    return alpha == '=' || alpha == '>' || alpha == '<' || alpha == '+' || alpha == '-' || alpha == '*' || alpha == '/' || alpha == '%' || alpha == '^';
}

bool f_is_oper(char alpha)
{
    return alpha == '=' || alpha == '>' || alpha == '<' || alpha == '+' || alpha == '-' || alpha == '*' || alpha == '/' || alpha == '%' || alpha == '^' || alpha == '~';
}

bool f_is_parenthesis(char alpha)
{
    return alpha == ')' || alpha == '(';
}

int f_precedence(char alpha)
{
    switch(alpha)
    {
        case '=':
            return 0;

        case '<':
        case '>':
            return 1;

        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
        case '%':
            return 3;

        case '^':
            return 4;

        case '~':
            return 5;

        default:
            return 0;
    }
}

Associativity f_associativity(char alpha)
{
    switch(alpha)
    {
        case '=':
            return Associativity::right;

        case '<':
        case '>':
            return Associativity::left;

        case '+':
        case '-':
            return  Associativity::left;

        case '*':
        case '/':
        case '%':
            return  Associativity::left;

        case '^':
            return Associativity::right;

        case '~':
            return Associativity::right;

        default:
            return Associativity::left;
    }
}

string f_infix_to_rpn(string input)
{
        stack<char> stos;
        stack<char> temp;
        string rpn;
        char token;

        string infix = f_delete_white_spaces_and_wrong_chars(input);
        if(!f_check_if_infix_is_valid(infix))
        {
            return "error";
        }

        for(size_t i = 0; i < infix.size(); i++)
        {
            token = infix[i];
            if(f_is_oper(token))
            {
                if(stos.size() > 0)
                {
                    while(!stos.empty() && ((f_associativity(token) == Associativity::left) && (f_precedence(token) <= f_precedence(stos.top()))) || 
                    ((f_associativity(token) == Associativity::right) && (f_precedence(token) < f_precedence(stos.top()))))
                    {
                        rpn += stos.top();
                        stos.pop();
                    }
                }
                stos.push(token);
            }
            else if(token == '(')
            {
                stos.push(token);
            }
            else if(token == ')')
            {
                while(!stos.empty() && stos.top() != '(')
                {
                    rpn += stos.top();
                    stos.pop();
                }
                if(!stos.size())
                {
                    return "error";
                }
                stos.pop();
            }
            else
            {
                rpn += token;
            }
        }

        while(!stos.empty())
        {
            if(f_is_oper(stos.top()))
            {
                rpn += stos.top();
                //output.push(stos.top());
            }
            stos.pop();
        }

        return rpn;
}