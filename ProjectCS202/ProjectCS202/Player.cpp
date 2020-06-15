#include"Player.h"

bool Player:: win(){
	return (x==1);
}

void Player:: Inc_Score(int &Sc,const int&level){
	if(x!=sizeRoad_h-4){
		Sc+=min(500,level*(sizeRoad_h-x));
	}

}

void Player:: level_UP(){
	speed=max(speed-20,0);
	health+=1;
	x=sizeRoad_h-4;
	y=sizeRoad_w/2-1;
}

int Player::get_health(){
	return health;
}


void Player:: hurt(){
	health=max(0,health-1);
	x=sizeRoad_h-4;
	y=sizeRoad_w/2-1;
}

bool Player:: die(){
	return (health==0);
}

void Player:: move(){

}

Player:: Player(){
		x=sizeRoad_h-4;
		y=sizeRoad_w/2-1;
		health=3;
		shape_type=0;
		shape.get_player_shape(0);
		speed=100;
}




