#include"Road.h"
#include"Shape.h"
bool Road:: put(int x,int y, Shape t){
	string tmp[3];
	bool overlap=0;
	tmp[0]=t.get_1();
	tmp[1]=t.get_2();
	tmp[2]=t.get_3();
	int moveY;
	int n=tmp[0].size();
	for(int i=0;i<3;++i)
		for(int j=0;j<n;++j){
			moveY=mod(y-1+j,weight-2)+1;
			if(road[x+i][moveY]!=' ') {
				overlap=1;
				road[x+i][moveY]='X';
			}
			else road[x+i][moveY]=tmp[i][j];
		}
	return overlap;
}

void Road:: clear(){
	for(int i=1;i<height-1;++i){
		for(int j=1;j<weight-1;++j){
			road[i][j]=' ';
		}
	}
}

void Road:: show(){
	gotoxy(0,0);
	for(int i=0;i<height;++i)
		cout<<road[i];
}
Road::Road(){
	weight=height=50;

	for(int i=0;i<height;++i){
		road[i]="";
		for(int j=0;j<weight;++j){
			if(i==0||j==0||i==height-1||j==weight-1)
				road[i]+='#';
			else road[i]+=' ';
		}
		road[i]+='\n';
	}
}

void Road:: setLight(int y, bool sw) {
	for (int i = 0; i < 3; ++i) {
		road[y + i][0] = road[y + i][49] = (sw ? 'O' : '#');
	}
}
