#include "File.hpp"
#include "Array.hpp"
#include <fstream>
using namespace std;

C_matrix_size f_read_matrix_size_from_file(const char* path)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z odczytaniem rozmiaru macierzy");
    }

    C_matrix_size m_size;
    file >> m_size.rows;

    unsigned int largest_vertex{1};
    unsigned int temp{0};

    while(file >> temp)
    {
        if(temp > largest_vertex)
        {
            largest_vertex = temp;
        }
    }

    m_size.cols = largest_vertex;
    file.close();
    return m_size;
}

int* f_read_edges_from_file(const char* path, C_matrix_size m_size)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z odczytaniem krawdedzi grafu");
    }

    int* edges = f_create_array<int>(m_size.rows * 2);

    int temp;
    file >> temp;

    int i{};
    while(file >> temp)
    {
        edges[i] = temp - 1;
        i++;
    }

    file.close();
    return edges;
}

void f_save_to_file_first(const char* path, int** incidence_matrix, C_matrix_size m_size, int** neighbours, std::vector<std::vector<int>> incidience_vector, const std::vector<std::vector<int>>& neighbours_vec)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z zapisem do pliku pierwszego zadania");
    }

    file << "Macierz incydencji (tablica dynamiczna):" << endl;
    for(int i = 0; i < m_size.rows; i++)
    {
        for(int j = 0; j < m_size.cols; j++)
        {
            file << incidence_matrix[i][j] << " ";
        }
        file << endl;
    }

    file << "\nMacierz incydencji (std::vector):" << endl;
    for(const auto& rows : incidience_vector)
    {
        for(const auto& e : rows)
        {
            file << e << " ";
        }
        file << endl;
    }

    file << "\nWszyscy sasiedzi dla danego wierzcholka (tablica dynamiczna):" << endl;
    for(int i = 0; i < m_size.cols; i++)
    {
        file << i + 1 << ": ";
        for(int j = 0; j < m_size.cols; j++)
        {
            if(neighbours[i][j] != 0)
            {
                file << neighbours[i][j] << " ";
            }
        }
        file << endl;
    }

    file << "\nWszyscy sasiedzi dla danego wierzcholka (std::vector):" << endl;
    for(int i = 0; i < neighbours_vec.size(); i++)
    {
        file << i + 1 << ": ";
        for(int j = 0; j < neighbours_vec.at(i).size(); j++)
        {
            if(neighbours_vec.at(i).at(j) != 0)
            {
                file << neighbours_vec.at(i).at(j) << " ";
            }
        }
        file << endl;
    }

    file.close();
}

void f_save_to_file_second(const char* path, const std::vector<C_linked_list>& inc_list, const std::vector<std::list<int>>& inc_list_sec, const std::vector<std::list<int>>& d_list, const std::vector<std::list<int>>& d_list_second)
{
    ofstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem z zapisem do pliku pierwszego zadania");
    }

    int i = 1;
    file << "Lista incydencji (klasa):\n";
    for(const auto& e : inc_list)
    {
        file << i << ": " << e.str();
        file << endl;
        i++;
    }

    i = 1;
    file << "\nLista incydencji (std::list):\n";
    for(const auto& e : inc_list_sec)
    {
        file << i << ": ";
        for(const auto& f : e)
        {
            file << f << " ";
        }
        i++;
        file << endl;
    }

    i = 1;
    file << "\nStopnie wierzcholkow (klasa):\n";
    for(const auto& e : d_list)
    {
        file << i << ": ";
        for(const auto& f : e)
        {
            file << f << " ";
        }
        file << endl;
        i++;
    }

    i = 1;
    file << "\nStopnie wierzcholkow (std::list):\n";
    for(const auto& e : d_list_second)
    {
        file << i << ": ";
        for(const auto& f : e)
        {
            file << f << " ";
        }
        file << endl;
        i++;
    }

    file.close();
}