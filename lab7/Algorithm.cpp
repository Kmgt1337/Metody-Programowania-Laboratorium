#include "Algorithm.hpp"
#include <iostream>
using namespace std;

pair<int, int> f_search_first_occuerence_iter(const vector<vector<int>>& matrix, int key)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        int start = 0;
        int end = matrix.at(0).size() - 1;
        int first_pos = -1;
            
        while(start <= end) 
        {
            int mid = (start + end) / 2;
            if(key == matrix.at(i).at(mid)) 
            {
                first_pos = mid;
                end = mid - 1;
            } 
            else if (key < matrix.at(i).at(mid)) 
            {
                end = mid - 1;
            } 
            else 
            {
                start = mid + 1;
            }
        }
            
        if(first_pos >= 0 && key == matrix.at(i).at(first_pos))
        {
            return {i, first_pos};
        }
    }
        
    return {-1, -1};
}

pair<int, int> f_search_last_occuerence_iter(const vector<vector<int>>& matrix, int key)
{
    for(int i = matrix.size() - 1; i >= 0; i--)
    {
        int start = 0;
        int end = matrix.at(0).size() - 1;
        int first_pos = -1;
            
        while(start <= end) 
        {
            int mid = (start + end) / 2;
            if(key == matrix.at(i).at(mid)) 
            {
                first_pos = mid;
                start = mid + 1;
            } 
            else if (key < matrix.at(i).at(mid)) 
            {
                end = mid - 1;
            } 
            else 
            {
                start = mid + 1;
            }
        }
            
        if(first_pos >= 0 && key == matrix.at(i).at(first_pos))
        {
            return {i, first_pos};
        }
    }
        
    return {-1, -1};
}

int f_first_occurence_binary_rec(const std::vector<int>& arr, int low, int high, int key)
{
    if (high >= low) 
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || key > arr.at(mid - 1)) && arr.at(mid) == key)
        {
            return mid;
        }
        else if (key > arr.at(mid))
        {
            return f_first_occurence_binary_rec(arr, mid + 1, high, key);
        }
        else
        {
            return f_first_occurence_binary_rec(arr, low, mid - 1, key);
        }
    }
    return -1;
}

std::pair<int, int> f_search_first_occuerence_rec(const std::vector<std::vector<int>>& matrix, int key)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        int first_pos = f_first_occurence_binary_rec(matrix.at(i), 0, matrix.at(i).size() - 1, key);
        if(first_pos >= 0 && key == matrix.at(i).at(first_pos))
        {
            return {i, first_pos};
        }
    }

    return  {-1, -1};
}

int f_last_occurence_binary_rec(const std::vector<int>& arr, int low, int high, int key)
{
    if (high >= low) 
    {
        int mid = low + (high - low) / 2;
        if ((mid == arr.size() - 1 || key < arr.at(mid + 1)) && arr.at(mid) == key)
        {
            return mid;
        }
        else if (key < arr.at(mid))
        {
            return f_last_occurence_binary_rec(arr, low, mid - 1, key);
        }
        else
        {
            return f_last_occurence_binary_rec(arr, mid + 1, high, key);
        }
    }

    return -1;
}

std::pair<int, int> f_search_last_occuerence_rec(const std::vector<std::vector<int>>& matrix, int key)
{
    for(int i = matrix.size() - 1; i >= 0; i--)
    {
        int last_pos = f_last_occurence_binary_rec(matrix.at(i), 0, matrix.at(i).size() - 1, key);
        if(last_pos >= 0 && key == matrix.at(i).at(last_pos))
        {
            return {i, last_pos};
        }
    }

    return  {-1, -1};
}