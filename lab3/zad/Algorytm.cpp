#include "Algorytm.hpp"

int f_wysz_binarne_najmniejszy_indeks(long long* tab, int rozmiar, int szukana)
{
    int start = 0;
    int koniec = rozmiar - 1;

    int pierwsza_pozycja = -1;
        
    while(start <= koniec) 
    {
        int srodek = (start + koniec) / 2;
        if(szukana == tab[srodek]) 
        {
            pierwsza_pozycja = srodek;
            koniec = srodek - 1;
        } 
        else if (szukana < tab[srodek]) 
        {
            koniec = srodek - 1;
        } 
        else 
        {
            start = srodek + 1;
        }
    }

    return pierwsza_pozycja;
}

int f_wysz_binarne_najwiekszy_indeks(long long* tab, int rozmiar, int szukana)
{
   int start = 0;
   int koniec = rozmiar - 1;

   int ostatnia_pozycja = -1;

    while(start <= koniec) 
    {
        int mid = (start + koniec) / 2;

        if(szukana == tab[mid]) 
        {
            ostatnia_pozycja = mid;
            start = mid + 1;
        } 
        else if (szukana < tab[mid]) 
        {
            koniec = mid - 1;
        } 
        else 
        {
            start = mid + 1;
        }
    }

    return ostatnia_pozycja;
}

int f_zlicz_ile_elementow(long long* tab, int rozmiar, int szukana)
{
    int najmniejszy = f_wysz_binarne_najmniejszy_indeks(tab, rozmiar, szukana);
    int najwiekszy = f_wysz_binarne_najwiekszy_indeks(tab, rozmiar, szukana);

    if(najmniejszy == -1 || najwiekszy == -1)
    {
        return 0;
    }

    return najwiekszy - najmniejszy + 1;
}   

int f_wysz_interpolacyjne(long long* tab, int rozmiar, int szukana)
{
    int ip = 0;
    int ik = rozmiar - 1;
    int isr;

    if(tab[ip] == szukana)
    {
        return ip;
    }

    while((tab[ ip ] <= szukana) && (szukana <= tab[ ik ]))
    {
        isr = ip + (szukana - tab[ ip ]) * (ik - ip) / ((tab[ ik ] - tab[ ip ]));

        if(tab[ isr ] == szukana)
        {
           return isr;
        }
        else if(szukana < tab[ isr ])
        {
            ik = isr - 1;
        }
        else
        {
            ip = isr + 1;
        }
    }

    return -1;
}

int f_usun_duplikaty(long long* tab, int rozmiar)
{
    if (rozmiar == 0 || rozmiar == 1)
    {
        return rozmiar;
    }
  
    int j = 0;
  
    for (int i = 0; i < rozmiar - 1; i++)
    {
        if (tab[i] != tab[i + 1])
        {
            tab[j] = tab[i];
            j++;
        }
    }
  
    tab[j] = tab[rozmiar - 1];
    j++;
  
    return j;
}