#include "Huffman.hpp"
#include "MyExceptions.hpp"

#include <algorithm>

using namespace std;

Node* f_create_new_node(char ch, int freq, double prob, Node* left, Node* right)
{
    Node* node = new Node();

    node->_ch = ch;
    node->_freq = freq;
    node->_prob = prob;
    node->_right = right;
    node->_left = left;

    return node;
}

Huffman_coding::Huffman_coding(string txt)
{
    if(!txt.size())
    {
        throw myexceptions::EmptyTextException();
    }

    _mode = OPERATING_MODE::TEXT_MODE;
    _txt = txt;

    for(const auto& ch : _txt)
    {
        _char_map[ch]++;
    }

    set_comparator();
    make_huffman_tree();
    create_huffman_codes(_root, "");

    _encoded_text = encode_text(_txt);
    _decoded_text = decode_text(_encoded_text);
}

void Huffman_coding::check_freq_mode_map()
{
    for(const auto& e : _char_map)
    {
        if(e.second < 1)
        {
            throw myexceptions::BadValueInMapException("Czestotliwosc nie moze byc mniejsza od 1. Wartosc: " + to_string(e.second));
        }

        if(static_cast<int>(e.second) != e.second)
        {
            throw myexceptions::BadValueInMapException("Czestotliwosc nie moze byc liczba dziesietna. Wartosc: " + to_string(e.second));
        }
    }  
}

void Huffman_coding::check_prob_mode_map()
{
    float total_prob = 0.f;

    for(const auto& e : _char_map)
    {
        if(e.second < 0 || e.second > 1)
        {
            throw myexceptions::BadValueInMapException("Prawdopodobienstwo nie moze byc mniejsze od zera lub wieksze od 1. Wartosc: " + to_string(e.second));
        }
                
        total_prob += e.second;
    }

    if(total_prob > 1)
    {
        throw myexceptions::BadValueInMapException("Laczne prawdopodobnienstwo nie moze byc wieksze niz 1. Wartosc: " + to_string(total_prob));
    }
}

Huffman_coding::Huffman_coding(const unordered_map<char, float>& char_map, OPERATING_MODE mode)
{
    if(!char_map.size())
    {
        throw myexceptions::EmptyCharacterMapException();
    }

    _char_map = char_map;
    _mode = mode;

    switch(_mode)
    {
        case OPERATING_MODE::FREQ_MODE:
        {
            check_freq_mode_map();
            break;
        }

        case OPERATING_MODE::PROB_MODE:
        {
            check_prob_mode_map();
            break;
        }
    }

    set_comparator();
    make_huffman_tree();
    create_huffman_codes(_root, "");

    _encoded_text = "$";
    _decoded_text = "$";
}

void Huffman_coding::set_comparator()
{
    switch(_mode)
    {
        case OPERATING_MODE::TEXT_MODE:
        case OPERATING_MODE::FREQ_MODE:
        {
            _comp = [](const Node* left, const Node* right)
            {
                return left->_freq > right->_freq;
            };

            break;
        }

        case OPERATING_MODE::PROB_MODE:
        {
            _comp = [](const Node* left, const Node* right)
            {
                return left->_prob > right->_prob;
            };

            break;
        }
    }
}

void Huffman_coding::set_priority_queue(std::priority_queue<Node*, std::vector<Node*>, decltype(_comp)>& pq)
{
    switch(_mode)
    {
        case OPERATING_MODE::TEXT_MODE:
        {
            int elements_count = 0;
            for(const auto& e : _char_map)
            {
                 elements_count += e.second;
            }

            for(const auto& e : _char_map)
            {
                pq.push(f_create_new_node(e.first, e.second, e.second / static_cast<double>(elements_count), nullptr, nullptr));
            } 

            break;
        }

        case OPERATING_MODE::FREQ_MODE:
        {
            for(const auto& e : _char_map)
            {
                pq.push(f_create_new_node(e.first, e.second, 0, nullptr, nullptr));
            } 
            break;
        }

        case OPERATING_MODE::PROB_MODE:
        {
            for(const auto& e : _char_map)
            {
                pq.push(f_create_new_node(e.first, 0, e.second, nullptr, nullptr));
            } 
            break;
        }
    }
}

void Huffman_coding::make_huffman_tree()
{
    priority_queue<Node*, vector<Node*>, decltype(_comp)> pq(_comp);
    set_priority_queue(pq);

    while(pq.size() != 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();
        
        pq.push(f_create_new_node('$', left->_freq + right->_freq, left->_prob + right->_prob, left, right));
    }

    _root = pq.top();
}

void Huffman_coding::create_huffman_codes(Node* root, std::string txt)
{
    if(!root)
    {
        return;
    }

    if(!root->_left && !root->_right)
    {
        _huffman_codes[root->_ch] = txt;
    }

    create_huffman_codes(root->_left, txt + "0");
    create_huffman_codes(root->_right, txt + "1");
}

std::string Huffman_coding::encode_text(std::string txt)
{
    std::string encoded;

    for(const auto& ch : txt)
    {
        encoded += _huffman_codes[ch];
    }

    return encoded;
}

std::string Huffman_coding::decode_text(std::string txt)
{
    std::string decoded;
    Node* curr = _root;
    for(size_t i = 0; i < txt.size(); i++)
    {
        if(txt.at(i) == '0')
        {
            curr = curr->_left;   
        }
        else
        {
            curr = curr->_right;
        }

        if(!curr->_left && !curr->_right)
        {
            decoded += curr->_ch;
            curr = _root;
        }
    }

    return decoded;
}