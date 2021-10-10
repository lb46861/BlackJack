#pragma once
#include "igrac.h"
#include "dek.h"
#include "dealer.h"
using namespace std;
class Game
{
	Dek dek;
	Dealer dealer;
	vector<Igrac> igraci;
public:
	Game();
	~Game();
	void postavi_igrace();
	void start();
};