#include"Header.h"

int mod(int a,int b){
	int t=a%b;
	if(t<0) t+=b;
	return t;
}


void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void gotoxy (int x, int y)
{
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates
}

void FixConsoleWindow() {
 HWND consoleWindow = GetConsoleWindow();
 LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
 style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
 SetWindowLong(consoleWindow, GWL_STYLE, style);
}