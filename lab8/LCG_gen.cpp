#include "LCG_gen.hpp"
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

LCG_gen::LCG_gen(int x_min, int x_max, int seed)
{
    _x_min = x_min;
    _x_max = x_max;
    _m = x_max + 1;
    _prev = seed;
    _primes_m = calc_primes(_m);
    _c = calc_increment();
    _a = calc_multiplier();
}

int LCG_gen::rand()
{
    int x = (_a * _prev + _c) % _m;
    _prev = x;

    return x % _x_max + _x_min;
}

int LCG_gen::calc_increment()
{
    for(int i = 2; i < _m; i++)
    {
        for(const auto& prime : _primes_m)
        {
            if(i != prime)
            {
                return i;
            }
        }
    }

    return 0;
}

int LCG_gen::calc_multiplier()
{
    vector<pair<int, int>> candidates;

    for(int a = 2; a < _m; a++)
    {
        int lambda = 1;
        while(true && lambda < 1000)
        {
            double pw = ceil(pow(a, lambda));
            if(fmod(pw, _m) == 1)
            {
                candidates.push_back(make_pair(a, lambda));
                break;
            }
            lambda++;
        }
    }

    auto max_lambda = *max_element(candidates.begin(), candidates.end(), 
    [](const auto& lhs, const auto& rhs)
    {
        return lhs.second < rhs.second;
    });

    vector<pair<int, int>> max_candidates;
    for(const auto& e : candidates)
    {
        if(e.second == max_lambda.second)
        {
                max_candidates.push_back(e);
        }
    }

    for(const auto& e : max_candidates)
    {
        int b = e.second - 1;
        if(check_second_statement(b) && check_third_statement(b))
        {
            return e.first;
        }
    }

    auto max_a = *max_element(max_candidates.begin(), max_candidates.end(), 
    [](const auto& lhs, const auto& rhs)
    {
         return lhs.first < rhs.first;
    });

    return max_a.first;
}

bool LCG_gen::check_second_statement(int b)
{
    for(const auto& prime : _primes_m)
    {
        if(b % prime)
        {
            return false;
        }
    }
    return true;
}

bool LCG_gen::check_third_statement(int b)
{
    if((!_m % 4) && (!b % 4))
    {
        return true;
    }
    return false;
}

vector<int> LCG_gen::calc_primes(int n)
{
    vector<int> primes;
    int sq = sqrt(n); 
    int k = 2;

    while(n > 1 && k <= sq)
    {
        while(n % k == 0)
        {
            primes.push_back(k);
            n /= k;
        }
        ++k;
    }

    if(!primes.size())
    {
        primes.push_back(n);
    }

    return primes;
}