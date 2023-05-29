#include "Funkcje.hpp"
#include <cmath>
#include <iostream>
using namespace std;

int f_wielomian(int N, const int* a, int x)
{
    if(N == 0)
    {
        return a[0];
    }

    return a[N] * pow(x, N) + f_wielomian(N - 1, a, x);
}

const int* f_maximum(int N, const int* t)
{
    if(N <= 0 || t == nullptr)
    {
        return t;
    }

    const int* wartosc = f_maximum(N - 1, t);
    if(t[N - 1] > *wartosc)
    {
        return t + N - 1;
    }
    else
    {
        return wartosc;
    }
}

int f_newton(int N, int K)
{
    if(K == N || K  == 0)
    {
        return 1;
    }

    if(K <= N && N <= 33)
    {
        return f_newton(N - 1, K - 1) + f_newton(N - 1, K);
    }

    if(N < K)
    {
        return 0;
    }
    if(N > 33 || K > 33)
    {
        return -1;
    }
}

bool test_true(int cos)
{
    return true;
}

bool test_false(int cos)
{
    return false;
}

unsigned int f_srednia_warunkowa(double& s, bool(*f)(int), const int* b, const int* e)
{
    int n = e - b;
    if(n < 1)
    {
        return n;
    }

    static unsigned int licznik = 0;
    static double suma = 0;

    if(f(*e))
    {
        f_srednia_warunkowa(s, f, b, e - 1);
        suma += b[n - 1];
        s = suma / n;
        licznik++;
        return licznik;
    }
    else
    {
        return static_cast<unsigned int>(f(*e));
    }
}

bool f_suma_wazona(double& s, const double* b, const double* e, const double* a)
{
    int n = e - b;
    if(n < 0)
    {
        return true;
    }
    
    if(b[0] < 0 || e[n - 1] < 0) 
    {
        return false;
    }
 
    static double suma = 0;
    suma += b[n];
    if(suma >= 1) 
    {
        return false;
    }
 
    bool wynik = f_suma_wazona(s, b, e - 1, a);
 
    static double w1 = 0;
    static double w2 = 1;
 
    if(n > 0 && wynik) 
    {
        w1 += a[n - 1] * b[n - 1];
        w2 -= b[n - 1];
 
        s = w1 + a[n] * w2;
    }
 
    return wynik;
} 