#include <iostream>
#include <time.h>
#include "game.h"
using namespace std;
int main()
{
	srand(time(0));
	Game game;
	game.postavi_igrace();
	game.start();
}