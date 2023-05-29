#include "List.hpp"
#include <iostream>
#include <string>
using namespace std;

C_linked_list::C_linked_list()
{
    _head = nullptr;
}

void C_linked_list::push_back(int data)
{
    C_node* temp = new C_node(data);

    if (!_head)
    {
        _head = temp;
    }
    else
    {
        temp->_next = _head;
        _head = temp;
    }
}

std::string C_linked_list::str() const
{
    C_node* temp = _head;
    std::string s;
    while(temp != nullptr)
    {
        s += to_string(temp->_data) + " ";
        temp = temp->_next;
    }

    return s;
}

int C_linked_list::size() const
{
    int size{};
    C_node* temp = _head;

    while (temp != nullptr) 
    {
        size++;
        temp = temp->_next;
    }

    return size;
}
