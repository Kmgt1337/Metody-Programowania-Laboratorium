#include "Algorytm.hpp"
#include "Pliki.hpp"
#include "Tablice.hpp"

void f_znajdz_wszystkie_podzbiory(int n, const char* sciezka)
{
    f_wyczysc_plik(sciezka);

    int* B = f_stworz_tablice(n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        B[i] = 0;
    }
    
    int i = 0, p = 0, j = 0;
    do
    {
        f_pisz_do_pliku(sciezka, B, n);
        i = i + 1; p = 1; j = i;
        while (j % 2 == 0)
        {
            j = j / 2;
            p = p + 1;
        }
        if(p <= n)
        {
            B[p] = 1 - B[p];
        }
        
    }while(p <= n);

    f_usun_tablice(B);
}

void f_znajdz_wszystkie_kelementowe_podzbiory(int n, int k, const char* sciezka)
{
    f_wyczysc_plik(sciezka);

    int* A = f_stworz_tablice(k + 1);
    
    for(int i = 1; i <= k; i++)
    {
        A[i] = i;
    }
    
    int p = k;
    while(p >= 1)
    {
        f_pisz_do_pliku(sciezka, A, k);
        if(A[k] == n)
        {
            p = p - 1;
        }
        else
        {
            p = k;
        }
        if(p >= 1)
        {
            for(int i = k; i >= p; i--)
            {
                A[i] = A[p] + i - p + 1; 
            }
        }
    }

    f_usun_tablice(A);
}

void f_znajdz_podzialy_liczby(int n, const char* sciezka)
{
    f_wyczysc_plik(sciezka);

    int* S = f_stworz_tablice(n);
    int* R = f_stworz_tablice(n);

    S[1] = n; R[1] = 1; int d = 1; int sum{}; int l{};
    f_pisz_do_pliku_podzialy(sciezka, S, R, d);
    while(S[1] > 1)
    {
        sum = 0;
        if(S[d] == 1)
        {
            sum = sum + R[d];
            d = d - 1;
        }
        sum = sum + S[d]; R[d] = R[d] - 1; l = S[d] - 1;
        if(R[d] > 0)
        {
            d = d + 1;
        }

        S[d] = l;
        R[d] = sum / l;
        l = sum % l;

        if (l != 0)
        {
            d = d + 1;
            S[d] = l;
            R[d] = 1;
        }
        f_pisz_do_pliku_podzialy(sciezka, S, R, d);
    }

    f_usun_tablice(S);
    f_usun_tablice(R);
}