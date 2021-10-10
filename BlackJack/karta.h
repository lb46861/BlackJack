#pragma once
#include <iostream>
using namespace std;
class Karta
{
private:
	int br_karte = 0;
	int simbol = 0;
public:
	Karta();
	int get_broj_karte();
	int get_simbol_karte();
	void print_karta();
	Karta(int br_karte, int zog);
	~Karta();
};