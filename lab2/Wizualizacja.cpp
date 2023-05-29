#include "Wizualizacja.hpp"
#include <fstream>
using namespace std;

Wizualizacja::Wizualizacja(const char* sciezka_programu, double** siatki_silnika, unsigned int indeks_dopasowanej, double** siatki_nieznanego, unsigned int wiersze, unsigned int kolumny, int ktory_silnik)
{
    if(ktory_silnik == -1)
    {
        return;
    }

    sciezka_skryptu = sciezka_programu;
    size_t indeks = sciezka_skryptu.find_last_of('\\');
    std::string skrypt;

    if(indeks != string::npos)
    {
        sciezka_skryptu = sciezka_skryptu.substr(0, indeks);
        skrypt += "cd '" + sciezka_skryptu + "\\wizualizacja'\n";
    }

    skrypt += "set key left top\n";
    skrypt += "set key font ',20'\n";
    skrypt += "set xlabel 'X(t)' font ',15'\n";
    skrypt += "set ylabel 'Y(t)' font ',15'\n";
    skrypt += "set terminal pngcairo size 1900,1080\n";

    if(ktory_silnik == 0)
    {
        sciezka_danych_silnika += "wizualizacja\\dane_silnika_SEAK.txt";
        sciezka_danych_nieznanego += "wizualizacja\\dane_nieznanego_SEAK.txt";
        sciezka_skryptu += "\\wizualizacja\\skrypt_SEAK.txt";
        skrypt += "set output 'wykres_SEAK.png'\n";
        skrypt += "plot \"dane_silnika_SEAK.txt\" title 'Model w siatce identyfikacyjnej' smooth bezier lc rgb 'blue lw 10', \"dane_nieznanego_SEAK.txt\" title 'Nieznany model silnika' smooth bezier lc rgb 'red lw 10'\n";
    }

    if(ktory_silnik == 1)
    {
        sciezka_danych_silnika += "wizualizacja\\dane_silnika_SEB.txt";
        sciezka_danych_nieznanego += "wizualizacja\\dane_nieznanego_SEB.txt";
        sciezka_skryptu += "\\wizualizacja\\skrypt_SEB.txt";
        skrypt += "set output 'wykres_SEB.png'\n";
        skrypt += "plot \"dane_silnika_SEB.txt\" title 'Model w siatce identyfikacyjnej' smooth bezier lc rgb 'blue lw 10', \"dane_nieznanego_SEB.txt\" title 'Nieznany model silnika' smooth bezier lc rgb 'red lw 10'\n";
    }
    
    ofstream uchwyt(sciezka_skryptu);
    if(!uchwyt.good())
    {
        exit(-1);
    }
    uchwyt << skrypt;
    uchwyt.close();
    
    ofstream uchwyt_silnik(sciezka_danych_silnika);
    if(!uchwyt_silnik.good())
    {
        exit(-1);
    }
    for(unsigned int j = 6; j < kolumny; j++)
    {
        uchwyt_silnik << siatki_silnika[indeks_dopasowanej + 1][j] << " " << siatki_silnika[indeks_dopasowanej][j] << endl;
    }
    uchwyt_silnik.close();

    ofstream uchwyt_nieznany(sciezka_danych_nieznanego);
    if(!uchwyt_nieznany.good())
    {
        exit(-1);
    }
    for(unsigned int j = 6; j < kolumny; j++)
    {
        uchwyt_nieznany << siatki_silnika[1][j] << " " << siatki_silnika[0][j] << endl;
    }
    uchwyt_nieznany.close();
}

void Wizualizacja::uruchom_skrypt()
{
    std::string komenda = "gnuplot ";
    komenda += "\"" + sciezka_skryptu + "\"";
    system(komenda.c_str());
}