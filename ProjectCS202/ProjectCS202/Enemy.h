#ifndef _Enemy_h_
#define _Enemy_h_
#include"Shape.h"
#include"Header.h"
class Enemy {
	friend class Game;
private:
	int x, y;
	int direction; //1: left to right; -1: right to left;
	Shape shape;
public:
	static int speed,hard;
	static void setSpeed(int num);
	void grown();
	void move();
	void setLine(int line);
};

#endif 