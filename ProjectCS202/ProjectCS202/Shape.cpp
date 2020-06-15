#include"Shape.h"

Shape::Shape() {
	for (int i = 0; i < 3; ++i) {
		shape[i] = "";
	}
}

void Shape:: reverse_(){
	for(int i=0;i<3;++i)
		reverse(shape[i].begin(),shape[i].end());
}


void Shape:: grown(){
	Shape tmp;
	tmp.get_random_enemy_shape();
	for(int i=0;i<3;++i){
		shape[i]+="        ";
		shape[i]+=tmp.shape[i];
	}
}

void Shape:: set_1(string s){
	shape[0]=s;
}

void Shape:: set_2(string s){
	shape[1]=s;
}

void Shape:: set_3(string s){
	shape[2]=s;
}


string Shape::get_1(){
	return shape[0];
}

string Shape::get_2(){
	return shape[1];
}

string Shape::get_3(){
	return shape[2];
}
void Shape::get_enemy_shape(int type){
	switch(type){
	case 0:
		shape[0]=" >|";
		shape[1]="== ";
		shape[2]="O O";
		break;
	case 1:
		shape[0]=" /\\";
		shape[1]="/o=";
		shape[2]="O=O";
		break;
	case 2:
		shape[0]="HH ";
		shape[1]="HHH";
		shape[2]="O O";
		break;
	case 3:
		shape[0]="  /";
		shape[1]=" />";
		shape[2]="O O";
		break;
	case 4:
		shape[0]="}V{";
		shape[1]="}0{";
		shape[2]="} {";
		break;
	case 5:
		shape[0]="===";
		shape[1]=" O-";
		shape[2]="===";
		break;
	}

}

void Shape::get_player_shape(int type){
	switch(type){
	case 0:
		shape[0]=" O ";
		shape[1]="-=-";
		shape[2]="/ \\";
		break;
	case 1:
		shape[0]="^o^";
		shape[1]="|Y|";
		shape[2]=" M ";
		break;
	case 2:
		shape[0]="^o^";
		shape[1]="<Y>";
		shape[2]=" M ";
		break;
	case 3:		
		shape[0]=" | ";
		shape[1]="-O-";
		shape[2]=" | ";
		break;
	case 4:
		shape[0]="/^\\";
		shape[1]="^O^";
		shape[2]="^ ^";
		break;
	case 5:
		shape[0]="s2-";
		shape[1]="-s2";
		shape[2]="s2-";
		break;
	}
}

void Shape::get_random_enemy_shape(){
	get_enemy_shape((rand()%MST));
}



