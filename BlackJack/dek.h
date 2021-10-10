#pragma once
#include "karta.h"
#include <vector>
class Dek 
{
	vector<Karta> dek;
	int broj_karata = 0;
public:
	void promijesaj();
	void print_dek();
	int get_broj_karata();
	Karta podijeli_kartu();
	void set_dek();
	Dek();
	~Dek();
};