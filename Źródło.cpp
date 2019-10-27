#include <iostream>
#include <fstream>		//wprowadzenie stawki podatkowej do pliku, ewentualnie zapisywanie podatkow;
#include <cctype>		// na razie nie wiem czy sie przyda;

double podatek(unsigned int);
void wyswietlanie(double,unsigned int);

const double KWOTY[] = { 0,0.10,0.15,0.20 };
const int PROGI[] = { 5000,15000,35000 };

int main()
{
	unsigned int kwota;
	std::cout << "\aAby zakonczyc podaj wartosc ujemna badz nieliczbowa.\npodaj kwote zarobkow: ";
	while (std::cin >> kwota)
	{
		wyswietlanie(podatek(kwota), kwota);
		std::cout << "\npodaj kwote zarobkow: ";
	}
	if (!(std::cin))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cout << "koniec programu";
	std::cin.get();
	return 0;
}




double podatek(unsigned int kwota)
{
	double tax;
	if (kwota < PROGI[0])
		tax = KWOTY[0];
	else if (kwota < PROGI[1])
		tax = (kwota - PROGI[0])*KWOTY[1];
	else if (kwota < PROGI[2])
		tax = (kwota - PROGI[1])*KWOTY[2]+ (PROGI[1] - PROGI[0])*KWOTY[1];
	else 
		tax = (kwota - PROGI[2])*KWOTY[3] + (PROGI[1] - PROGI[0])*KWOTY[1] + (PROGI[2] - PROGI[1])*KWOTY[2];
	
	return tax;
}

void wyswietlanie(double podatek,unsigned int kwota)
{
	//std::cout.precision(6);
	std::cout << "Twoj podatek od kwoty " << kwota << "zl wynosi " << podatek << std::endl;
}