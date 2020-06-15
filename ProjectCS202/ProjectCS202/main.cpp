#include"Game.h"

int main(){
	//resizeConsole(70,100);
	Nocursortype();
	//resizeConsole(430, 680);
	//FixConsoleWindow();
	Game newGame;
	newGame.running();
	return 0;
}

