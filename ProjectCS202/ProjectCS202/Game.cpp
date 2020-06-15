#include"Game.h"
void Game:: level_UP(){
	int base=min(10000,Score/10);
	int mul=min(10,level);
	Score+=base*mul;
	level++;
	int lvUP=level/5;
	for(int i=0;i<14;++i){
		if(lvUP<4&&(level%5==0)) enemy[i].grown();
		enemy[i].y=rand()%(sizeRoad_w-2)+1;
	}
	Enemy::setSpeed(max(100, Enemy::speed - 10));
	player.level_UP();
	Start();
}

void Game::Light() {
	while (!Game_Over) {
		Sleep(level* 500);
		int num_Light = min(14, level / 4);
		int a[14];
		for (int i = 0; i < 14; ++i) {
			a[i] = i;
		}
		random_shuffle(a, a + 14);
		for (int i = 0; i < num_Light; ++i) {
			enemy[a[i]].direction = 0;
			road.setLight(enemy[a[i]].x, 1); // turn on light
		}
		Sleep(level * 200);
		for (int i = 0; i < num_Light; ++i) {
			enemy[a[i]].direction = (a[i] % 2 == 0 ? 1 : -1);
			road.setLight(enemy[a[i]].x, 0); // turn off light
		}
	}
}

void Game:: Start(){
	Game_Over = 0;
	Put2Road();
	thread t1(&Game::moving,this);
	thread t2(&Game::Player_move, this);
	thread t3(&Game::Light, this);
	Out_Health();
	Out_Score();
	while(!Game_Over){
		road.show();
		road.clear();

		if(Put2Road()==1){
			player.hurt();
			Out_Health();
			if(player.die()){
				road.show();
				Sleep(200);
				Game_Over=1;
				t1.join();
				t2.join();
				t3.join();
				return die_Menu();
			}
		}
		if(player.win()){
			road.show();
			Sleep(200);
			Game_Over=1;
			t1.join();
			t2.join();
			t3.join();
			return level_UP();
		}


		Out_Score();
		player.Inc_Score(Score,level);
	}
	t1.join();
	t2.join();
	t3.join();
}

void Game::Pause_Game() {
	int choose=Pause_Menu();
	switch (choose) {
	case 0:
		return Start();
	case 1:
		return running();
	}
}

void Game::Player_move() {
	while (!Game_Over) {
		int n = 3;
		int ms = 20;
		char t = '_';
		while (ms > 0) {
			if (_kbhit()) {
				t = _getch();
				break;
			}
			Sleep(ms);
			ms -= 20;
		}
		Sleep(player.speed);

		switch (t) {
			//move step by step
		case 'a':
			player.y = max(1, player.y - 1);
			break;
		case 's':
			player.x = min(sizeRoad_h - 4, player.x + 1);
			break;
		case 'w':
			player.x = max(1, player.x - 1);
			break;
		case 'd':
			player.y = min(sizeRoad_w - 4, player.y + 1);
			break;
			//jumb
		case 'A':
			player.y = max(1, player.y - n);
			break;
		case 'S':
			player.x = min(sizeRoad_h - 4, player.x + n);
			break;
		case 'W':
			player.x = max(1, player.x - n);
			break;
		case 'D':
			player.y = min(sizeRoad_w - 4, player.y + n);
			break;
		case ' ':
			player.x = sizeRoad_h - 4;
			break;
		case 'l': case 'L': 
			Game_Over = 1;
			Sleep(200);
			return Load();
		case 't': case 'T':
			Game_Over = 1;
			Sleep(200);
			return Save();
		case 'p':case'P':case 13:
			Game_Over = 1;
			Sleep(200);
			return Pause_Game();
		}
	}
}

void Game:: moving(){
	while(!Game_Over){
		for(int i=0;i<14;++i){
			enemy[i].move();
		}

		Sleep(Enemy::speed);
	}
}

void Game:: Options(){
	
	Options_Menu();

	int curr=20;
	char input;
	do{
		gotoxy(10,curr);
		cout<<">>>";
		input=_getch();
		gotoxy(10,curr);
		cout<<"   ";
		switch(input){
		case 's': case 'S':
			curr=min(35,curr+5);
			break;
		case 'w': case 'W':
			curr=max(20,curr-5);
			break;
		case '1':
			curr=20;
			break;
		case '2':
			curr=25;
			break;
		case '3':
			curr=30;
			break;

		case '4':
			curr = 35;
			break;
		}
	}while(input!=13);
	switch(curr){
	case 20: 
		return Out_HighScore();
	case 25:
		return Choose_Player();
	case 30:
		return Choose_Difficult();
	case 35:
		return running();
	}
}

void Game:: PutScore(){
	HighScore_List.push_back(Score);
	sort(HighScore_List.begin(),HighScore_List.end());
	reverse(HighScore_List.begin(), HighScore_List.end());
	int size=HighScore_List.size();
	HighScore_List.resize(min(size,10));
}




void Game:: Choose_Player(){
	
	Choose_Player_Menu();

	int curr;
	char input;
	curr=19;

	do{
		gotoxy(18,curr);
		cout<<">>>";
		input=_getch();
		gotoxy(18,curr);
		cout<<"   ";
		switch(input){
		case 's': case 'S':
			curr=min(43,curr+4);
			break;
		case 'w': case 'W':
			curr=max(19,curr-4);
			break;
		case '1':
			curr=19;
			break;
		case '2':
			curr=23;
			break;
		case '3':
			curr=27;
			break;
		case '4':
			curr=31;
			break;
		case '5':
			curr=35;
			break;
		case '6':
			curr=39;
			break;
		case '7':
			curr=43;
			break;
		}
	}while(input!=13);
	switch(curr){
	case 19: return setPlayer_Shape(0);
	case 23: return setPlayer_Shape(1);
	case 27: return setPlayer_Shape(2);
	case 31: return setPlayer_Shape(3);
	case 35: return setPlayer_Shape(4);
	case 39: return setPlayer_Shape(5);
	case 43: return Options();
	}

}




bool Game:: Load_Game(string name){
	ifstream in;
	in.open(name);
	if(!in.is_open()) return 0;
	/*
	Player player;
	Enemy enemy[14];
	vector<int> HighScore_List;
	int level;
	int highScore;
	int Score;
	*/
	//load data class Game
	in>>level>>Score>>highScore;
	int size;
	in>>size;
	for(int i=0;i<size;++i){
		int x; in>>x;
		HighScore_List.push_back(x);
	}
	/*
	int x,y;
	Shape shape;
	int health;
	int speed;
	int shape_type;
	*/
	//load data class Player
	in>>player.x>>player.y;
	in>>player.health>>player.speed;
	in>>player.shape_type;
	player.shape.get_player_shape(player.shape_type);
	/*
	int x,y;
	int direction; //1: left to right; -1: right to left;
	int speed;
	Shape shape;
	*/
	string s;
	for(int i=0;i<14;++i){
		in>>enemy[i].x>>enemy[i].y;
		in>>enemy[i].direction>>enemy[i].speed;
		in.ignore();
		getline(in,s); enemy[i].shape.set_1(s);
		getline(in,s); enemy[i].shape.set_2(s);
		getline(in,s); enemy[i].shape.set_3(s);
	}
	in.close();
	return 1;
}

bool Game:: Save_Game(string name){
	ofstream out;
	out.open(name);
	if(!out.is_open()) return 0;
	/*
	Player player;
	Enemy enemy[14];
	vector<int> HighScore_List;
	int level;
	int highScore;
	int Score;
	*/
	//load data class Game
	out<<level<<' '<<Score<<' '<<highScore<<endl;
	int size; size=HighScore_List.size();
	out<<size<<endl;
	for(int i=0;i<size;++i) 
		out<<HighScore_List[i]<<endl;
	/*
	int x,y;
	Shape shape;
	int health;
	int speed;
	int shape_type;
	*/
	//load data class Player
	out<<player.x<<' '<<player.y<<endl;
	out<<player.health<<' '<<player.speed<<endl;
	out<<player.shape_type<<endl;
	/*
	int x,y;
	int direction; //1: left to right; -1: right to left;
	int speed;
	Shape shape;
	*/
	for(int i=0;i<14;++i){
		out<<enemy[i].x<<' '<<enemy[i].y<<endl;
		out<<enemy[i].direction<<' '<<enemy[i].speed<<endl;
		out<<enemy[i].shape.get_1()<<endl;
		out<<enemy[i].shape.get_2()<<endl;
		out<<enemy[i].shape.get_3()<<endl;
	}
	out.close();
	return 1;
}


void Game:: Save(){
	road.clear();
	road.show();
	Out_Name();
	gotoxy(12,20);
	cout<<"~~----!!SAVE GAME!!----~~";
	string tail=".save";
	string name;
	while(name.size()==0){
	gotoxy(10,24);
	cout<<"                           ";
	gotoxy(10,24);
	cout<<"Enter name: "; cin>>name;
	}
	name+=tail;
	bool saveSuccess;

   saveSuccess=Save_Game(name);
	
	if(saveSuccess){
		gotoxy(12,26);
		cout<<"~~----!!SUCCESSFULLY!!----~~";
	}
	else {
		gotoxy(12, 26);
		cout << "~~----!!Save error!!----~~";
	}

	gotoxy(15,44);
	cout<<"Enter a charactor to continue";
	_getch();
	Start();

}

void Game:: Load(){
	road.clear();
	road.show();
	Out_Name();
	gotoxy(12,20);
	cout<<"~~----!!LOAD GAME!!----~~";
	string tail=".save";
	string name;
	while(name.size()==0){
	gotoxy(10,24);
	cout<<"                            ";
	gotoxy(10,24);
	cout<<"Path and name: "; cin>>name;
	}
	name+=tail;
	bool LoadSuccess;

   LoadSuccess=Load_Game(name);
	
	if(LoadSuccess){
		gotoxy(12,26);
		cout<<"~~----!!SUCCESSFULLY!!----~~";
	}
	else {
		gotoxy(12, 26);
		cout << "~~----!!Load error!!----~~";
	}


	gotoxy(15,44);
	cout<<"Enter a charactor to Start";
	_getch();
	Start();
}

void Game:: Exit(){
	road.clear();
	road.show();
	Out_Name();
	gotoxy(5,22);
	cout<<"SEE YOU AGAIN!!!!! ";
	gotoxy(0,52);
}

bool Game:: Put2Road(){
	bool overlap=0;
	for(int i=0;i<14;++i){
		overlap|=road.put(enemy[i].x,enemy[i].y,enemy[i].shape);
	}
	overlap|=road.put(player.x,player.y,player.shape);
	return overlap;
}


Game::Game(){
	highScore=0;
	Score=0;
	Game_Over=0;
	level=1;
	for(int i=0;i<14;++i){
		enemy[i].setLine(4+i*3);
		enemy[i].direction = (i % 2 == 0 ? 1 : -1);
		enemy[i].grown();
		enemy[i].y = rand() % (sizeRoad_w - 2) + 1;
	}
}



void Game:: running(){
	int choose=Load_Menu();
	switch(choose){
	case 0:
		return Start();
	case 1:
		return Load();
	case 2:
		return Options();
	case 3:
		return Exit();
	}
}

