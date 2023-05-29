#include "File.hpp"
#include <fstream>
using namespace std;

bool f_read_from_file(const char* source, std::vector<std::pair<std::string, std::string>>& inputs)
{
    ifstream file(source);
    if(!file.good())
    {
        return false;
    }  

    string line;

    while(getline(file, line))
    {
        size_t index_inf = line.find("INF");
        size_t index_rpn = line.find("ONP");

        if(index_inf != string::npos)
        {
            inputs.push_back(std::make_pair("INF", line.substr(index_inf + 4, line.size() - 1)));
        }
        else if(index_rpn != string::npos)
        {
            inputs.push_back(std::make_pair("ONP", line.substr(index_rpn + 4, line.size() - 1)));
        }
    }

    file.close();
    return true;
}

bool f_save_to_file(const char* file, const std::vector<std::pair<std::string, std::string>>& outputs)
{
    ofstream out(file);
    if(!out.good())
    {
        return false;
    }

    for(const auto& e : outputs)
    {
        out << e.first << ": " << e.second << std::endl;
    }

    out.close();
    return true;
}