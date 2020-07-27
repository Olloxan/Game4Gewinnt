
#include <iostream>
#include"Game4Gewinnt.h"

using namespace std;

int main()
{
	Game4Gewinnt game;
	
	for (size_t i = 0; i < 10; i++)
	{
		game.BeginNextTurn();
		game.ReleasePixel();
	}

	return 0;
}