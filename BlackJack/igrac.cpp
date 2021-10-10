#include "igrac.h"

string Igrac::get_ime()
{
	return this->ime;
}

int Igrac::get_broj_cipova()
{
	return this->broj_cipova;
}

int Igrac::ulozi(int ulog)
{
	if (this->broj_cipova >= ulog)
	{
		this->broj_cipova -= ulog;
		cout << "Ulog: " << ulog << endl;
		this->ulog = ulog;
		return 1;
	}
	else
		return 0;
}

int Igrac::getulog()
{
	return this->ulog;
}

void Igrac::reset_ulog()
{
	this->ulog = 0;
}


void Igrac::isplati(int dobitak)
{
	this->broj_cipova += dobitak;
}



Igrac::Igrac(string ime, int br_cipova)
{
	this->ime = ime;
	this->broj_cipova = br_cipova;
}

Igrac::Igrac()
{
}



Igrac::~Igrac()
{
}
