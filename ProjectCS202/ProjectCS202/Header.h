#ifndef _Header_h
#define _Header_h
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<thread>
#include<Windows.h>
#include<string>
#include<conio.h>
using namespace std;
class Player;
class Enemy;
class Game;
class Shape;
class Road;
const int sizeRoad_w=50;
const int sizeRoad_h=50;
const int MST=6; // max number of shape-types 




//func_console
void resizeConsole(int width, int height);
void gotoxy(int x,int y);
void FixConsoleWindow();
void Nocursortype();
int mod(int a,int b);
#endif