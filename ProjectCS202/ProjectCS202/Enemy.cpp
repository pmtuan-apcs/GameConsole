#include"Enemy.h"
int Enemy::speed = 200;
int Enemy::hard = 0;

void Enemy:: grown(){
	if(direction==-1){
		shape.reverse_();
	}
	shape.grown();
	if(direction==-1){
		shape.reverse_();
	}
	speed=200-hard*10;
}




void Enemy:: move(){
	y+=direction;
	if(y>=sizeRoad_w-1) y=1;
	if(y<=0) y=48;
}
void Enemy:: setLine(int line){
	x=line;
}

void Enemy:: setSpeed(int num){
	speed=num-hard*10;
}
