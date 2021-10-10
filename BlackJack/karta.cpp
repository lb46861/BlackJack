#include "karta.h"

Karta::Karta()
{
}

int Karta::get_broj_karte()
{
	if (this->br_karte == 11 || this->br_karte == 12 || this->br_karte == 13)
		return 10;
	else if (this->br_karte == 1)
		return 11;
	else
		return this->br_karte;
}

int Karta::get_simbol_karte()
{
	return this->simbol;
}

void Karta::print_karta()
{

	if (this->br_karte == 11)
		cout << "J" << " ";
	else if (this->br_karte == 12)
		cout << "Q" << " ";
	else if (this->br_karte == 13)
		cout << "K" << " ";
	else
		cout << this->br_karte << " ";

	if (this->simbol == 1)
		cout << "pik" << endl;
	else if (this->simbol == 2)
		cout << "herc" << endl;
	else if (this->simbol == 3)
		cout << "karo" << endl;
	else
		cout << "tref" << endl;
}



Karta::Karta(int br_karte, int simbol)
{
	this->br_karte = br_karte;
	this->simbol = simbol;
}

Karta::~Karta()
{
	this->br_karte = 0;
	this->simbol = 0;
}
