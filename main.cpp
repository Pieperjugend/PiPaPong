#include "main.h"
#include "Game.h"

/*
	using namespace std;
	using namespace sf;
*/

int main()
{
	//initialize game engine (Game)
	Game game; 

	//Game loop (stops when window closed) 1loop == 1frame 
	while (game.running())
	{
		//Update 
		game.update();

		//Render
		game.render(); 
	}
	//End of game | application 
	return 0;
}