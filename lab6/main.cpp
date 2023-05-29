#include "File.hpp"
#include "Array.hpp"
#include "Graph.hpp"
#include <iostream>

int main()
{
    try
    {
        std::string path, out_path;
        std::cin >> path >> out_path;

        C_matrix_size m_size = f_read_matrix_size_from_file(path.c_str());
        int* edges = f_read_edges_from_file(path.c_str(), m_size);
        int** incidence_matrix = f_create_incidence_matrix(edges, m_size.rows, m_size.cols);
        auto incidence_vec = f_create_incidence_vector(path.c_str(), m_size.cols);
        int** neighbours = f_calculate_all_neighbours_of_vertex(incidence_matrix, m_size.rows, m_size.cols);
        auto neighbours_vec = f_calculate_all_neighbours_of_vertex(incidence_vec);
        auto incidence_vector = f_create_incidence_vector(path.c_str(), m_size.cols);
        f_save_to_file_first(out_path.c_str(), incidence_matrix, m_size, neighbours, incidence_vector, neighbours_vec);

        f_delete_array(edges);
        f_delete_2d_array(incidence_matrix, m_size.rows);
        f_delete_2d_array(neighbours, m_size.cols);

        std::cout << "Zapisano do pliku " << out_path << " wyniki" << std::endl;

        std::cin >> path >> out_path;

        edges = f_read_edges_from_file(path.c_str(), m_size);
        auto incidence_list_first = f_create_incidence_list(edges, m_size);
        auto incidence_list_second = f_create_incidence_list_std(edges, m_size);
        auto degree_list = f_calculate_vertexes_degree(incidence_list_first, m_size.cols);
        auto degree_list_second = f_calculate_vertexes_degree_std(incidence_list_second, m_size.cols);
        f_save_to_file_second(out_path.c_str(), incidence_list_first, incidence_list_second, degree_list, degree_list_second);

        f_delete_array(edges);

        std::cout << "Zapisano do pliku " << out_path << " wyniki" << std::endl;
        std::cin.ignore();
        std::cin.get();
    }
    catch(problem_with_file& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
}