#include "Graph.hpp"
#include "Array.hpp"
using namespace std;

int** f_create_incidence_matrix(int* edges, int rows, int cols)
{
    int** matrix = f_create_2d_array<int>(rows, cols);

    int j = 1;
    for(int i = 0; i < rows; i++)
    {
        matrix[i][edges[j - 1]] = 1;
        matrix[i][edges[j]] = -1;
        j += 2;
    }

    return matrix;
}

vector<vector<int>> f_create_incidence_vector(const char* path, int cols)
{
    ifstream file(path);
    if(!file.good())
    {
        throw problem_with_file("Problem with creating incidence vector from file");
    }

    int temp;
    string line;
    getline(file, line);

    vector<vector<int>> incidence_vector;
    vector<int> temp_vec;

    while(getline(file, line))
    {
        temp_vec.clear();
        istringstream ss(line);
        while(ss >> temp)
        {
            temp_vec.push_back(temp);
        }
        vector<int> line_vec(cols, 0);

        line_vec.at(temp_vec.at(0) - 1) = 1;
        line_vec.at(temp_vec.at(1) - 1) = -1;

        incidence_vector.push_back(line_vec);
    }

    return incidence_vector;
}

int** f_calculate_all_neighbours_of_vertex(int** incidence_matrix, int rows, int cols)
{
    int** neighbours = f_create_2d_array<int>(cols, cols);
    int from = -1, to = -1;

    for(int i = 0; i < rows; i++)
    {
        from = -1;
        to = -1;
        for(int j = 0; j < cols; j++)
        {
            if(incidence_matrix[i][j] == 1)
            {
                from = j;
            }
            else if(incidence_matrix[i][j] == -1)
            {
                to = j;
            }
        }

        if(from != -1 && to != -1)
        {
            neighbours[from][to] = to + 1; 
        }
    }

    return neighbours;
}

vector<vector<int>> f_calculate_all_neighbours_of_vertex(const vector<vector<int>>& incidence_matrix)
{
    vector<vector<int>> neighbours;
    neighbours.resize(incidence_matrix.at(0).size());
    for(auto& e : neighbours)
    {
        e.resize(incidence_matrix.at(0).size());
    }

    int from = -1, to = -1;
    for(int i = 0; i < incidence_matrix.size(); i++)
    {
        from = -1;
        to = -1;
        for(int j = 0; j < incidence_matrix.at(i).size(); j++)
        {
            if(incidence_matrix.at(i).at(j) == 1)
            {
                from = j;
            }
            else if(incidence_matrix.at(i).at(j) == -1)
            {
                to = j;
            }
        }

        if(from != -1 && to != -1)
        {
            neighbours.at(from).at(to) = to + 1; 
        }
    }

    return neighbours;
}

void f_add_edge(vector<C_linked_list>& list, int src, int dst)
{
    list[src].push_back(dst + 1);
    list[dst].push_back(src + 1);
}

void f_add_edge(vector<list<int>>& list, int src, int dst)
{
    list[src].push_back(dst + 1);
    list[dst].push_back(src + 1);
}

vector<C_linked_list> f_create_incidence_list(int* edges, C_matrix_size size)
{
    vector<C_linked_list> incidence_list;
    incidence_list.resize(size.cols);

    for(int i = 0; i < size.rows * 2 - 1; i += 2)
    {
        f_add_edge(incidence_list, edges[i], edges[i + 1]);
    }

    return incidence_list;
}

vector<list<int>> f_create_incidence_list_std(int* edges, C_matrix_size size)
{
    vector<list<int>> incidence_list;
    incidence_list.resize(size.cols); 

    for(int i = 0; i < size.rows * 2 - 1; i += 2)
    {
        f_add_edge(incidence_list, edges[i], edges[i + 1]);
    }

    return incidence_list;
}

std::vector<std::list<int>> f_calculate_vertexes_degree(const vector<C_linked_list>& incidence_list, int num_of_vertex)
{
    std::vector<std::list<int>> degree_list;
    degree_list.resize(num_of_vertex);

    for(int i = 0; i < incidence_list.size(); i++)
    {
        degree_list[i].push_back(incidence_list.at(i).size());
    }

    return degree_list;
}

std::vector<std::list<int>> f_calculate_vertexes_degree_std(const std::vector<std::list<int>>& incidence_list, int num_of_vertex)
{
    std::vector<std::list<int>> degree_list;
    degree_list.resize(num_of_vertex);

    for(int i = 0; i < incidence_list.size(); i++)
    {
        degree_list[i].push_back(incidence_list.at(i).size());
    }

    return degree_list; 
}