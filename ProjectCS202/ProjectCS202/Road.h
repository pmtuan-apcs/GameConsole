#ifndef _Road_h_
#define _Road_h_
#include"Header.h"
#include"Shape.h"
class Road {
public:
	bool put(int x, int y, Shape t);
	void clear();
	void show();
	void setLight(int y, bool sw);
	Road();
private:
	string road[50];
	int weight;
	int height;
};

#endif