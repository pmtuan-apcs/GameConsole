#ifndef _Shape_h_
#define _Shape_h_
#include"Header.h"
class Shape {
public:
	Shape();
	void grown(); //grown when level_UP
	string get_1();//get three line of shape
	string get_2();
	string get_3();
	void set_1(string s);
	void set_2(string s);
	void set_3(string s);
	void get_random_enemy_shape();
	void get_enemy_shape(int type);
	void get_player_shape(int type);
	void reverse_();
private:
	string shape[3];
};
#endif // !_Shape_h_


