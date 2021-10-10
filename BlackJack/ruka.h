#pragma once
#include "karta.h"
#include <vector>
using namespace std;
class Ruka
{
protected:
	vector<Karta> ruka;
	int vrijednost = 0;
	int asevi = 0;
public:
	Ruka();
	~Ruka();
	void add_to_ruka(Karta karta);
	void reset_ruka();
	void reset_vrijednost();
	void povecaj_aseve();
	void smanji_aseve();
	void reset_asevi();
	int get_asevi();
	int get_vrijednost();
	int size();
	void change_vrijednost();
	Karta get_prva();
	void print_ruka();
};