#ifndef _Player_h_
#define _Player_h_
#include"Header.h"
#include"Shape.h"
class Player {
	friend class Game;
private:
	int x, y;
	Shape shape;
	int health;
	int speed;
	int shape_type;
public:
	int get_health();
	void Inc_Score(int &Sc, const int&level);
	void level_UP();
	bool win();
	void move();
	bool die();
	void hurt();
	Player();
};
#endif