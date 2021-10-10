#pragma once
#include "ruka.h"
class Igrac : public Ruka
{
	string ime;
	int broj_cipova = 0;
	int ulog = 0;
public:
	string get_ime();
	int get_broj_cipova();
	int ulozi(int ulog);
	int getulog();
	void reset_ulog();
	void isplati(int dobitak);
	Igrac(string ime, int br_cipova);
	Igrac();
	~Igrac();
};