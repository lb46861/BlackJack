#include "ruka.h"

Ruka::Ruka()
{
}

Ruka::~Ruka()
{
}

void Ruka::add_to_ruka(Karta karta)
{
	ruka.push_back(karta);
	this->vrijednost += karta.get_broj_karte();
}


void Ruka::reset_ruka()
{
	ruka.clear();
}

void Ruka::print_ruka()
{
	for (auto it = ruka.begin(); it != ruka.end(); it++)
	{
		it->print_karta();
	}
}

void Ruka::reset_vrijednost()
{
	this->vrijednost = 0;
}

void Ruka::povecaj_aseve()
{
	this->asevi += 1;
}

void Ruka::smanji_aseve()
{
	this->asevi -= 1;
}

void Ruka::reset_asevi()
{
	this->asevi = 0;
}

int Ruka::get_asevi()
{
	return this->asevi;
}

int Ruka::get_vrijednost()
{
	return this->vrijednost;
}

int Ruka::size()
{
	return ruka.size();
}

void Ruka::change_vrijednost()
{
	this->vrijednost -= 10;
}

Karta Ruka::get_prva()
{
	return ruka.front();
}

