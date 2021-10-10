#include "dek.h"

Dek::Dek()
{
}

void Dek::set_dek()
{
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			dek.push_back({ i, j });

			this->broj_karata += 1;
		}
	}
}

void Dek::promijesaj()
{
	Karta temp = dek[0];
	int i = rand() % dek.size();
	for (int j = 0; j < dek.size(); j++)
	{
		temp = dek[j];
		dek[j] = dek[i];
		dek[i] = temp;
		i = rand() % dek.size();
	}
}

void Dek::print_dek()
{
	int brojac = 0;
	for (auto it = dek.begin(); it != dek.end(); it++)
	{
		it->print_karta();
		brojac++;
	}
	cout << "Broj karata: " << brojac << endl;
}

int Dek::get_broj_karata()
{
	return this->broj_karata;
}

Karta Dek::podijeli_kartu()
{
	Karta my_card;
	my_card = dek.back();
	dek.pop_back();
	this->broj_karata -= 1;
	return my_card;
}

Dek::~Dek()
{
}
