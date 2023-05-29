#include "Algorytm.hpp"
#include <cmath>

C_wynik_algorytmu f_wyznacz_minimalny_blad_mse(double** siatki, unsigned int wiersze, unsigned int kolumny, double** nieznany, double* bledy_mse)
{
    double aktualny_blad{1000};
	double blad{};
    double sumy{};

	unsigned int indeks_bledow_mse{};
	unsigned int najlepszy_indeks_bledu{};

    for(unsigned int i = 0; i < wiersze - 1; i += 2)
    {
        sumy = 0;
        for(unsigned int j = 6; j < kolumny; j++)
        {
            sumy += std::pow(siatki[i][j] - nieznany[0][j], 2) + std::pow(siatki[i + 1][j] - nieznany[1][j], 2);
        }
        blad = std::sqrt(sumy);
		bledy_mse[indeks_bledow_mse] = blad;

		if(blad < aktualny_blad)
		{
			aktualny_blad = blad;
			najlepszy_indeks_bledu = i;
		}

		indeks_bledow_mse++;
    }

    return C_wynik_algorytmu{aktualny_blad, najlepszy_indeks_bledu};
}

int f_okresl_ktory_silnik(std::string nazwa)
{
    std::size_t indeks = nazwa.find("SEAK");
    if(indeks != std::string::npos)
    {
        return 0;
    }

    indeks = nazwa.find("SEB");
    if(indeks != std::string::npos)
    {
        return 1;
    }

    return -1;
}