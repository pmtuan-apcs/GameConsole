#include"Game.h"



void Game::Out_Health() {
	gotoxy(0, sizeRoad_h);
	cout << "                                                                           ";
	gotoxy(0, sizeRoad_h);
	cout << "Live: ";
	int n = min(6, player.get_health());
	for (int i = 0; i<n; ++i) {
		cout << "s2 ";
	}
}

void Game::Out_Score() {
	gotoxy(30, sizeRoad_h);
	cout << "                          ";
	gotoxy(30, sizeRoad_h);
	cout << "Score: " << Score;
}

void Game::Out_Control() {
	gotoxy(30, 36);
	cout << "[W]: UP";
	gotoxy(30, 38);
	cout << "[S]: DOWN";
	gotoxy(30, 40);
	cout << "[A]: LEFT";
	gotoxy(30, 42);
	cout << "[D]: RIGHT";
	gotoxy(30, 44);
	cout << "[CAPS LOCK]: JUMP";
	gotoxy(30, 46);
	cout << "[ENTER]: CHOOSE";
}

void Game::Out_Name() {
	gotoxy(3, 5); cout << "   =====    ==                         >>>>>>";
	gotoxy(3, 6); cout << "  ==   ==  =              ==       == >>  >>>";
	gotoxy(3, 7); cout << "  =        ====    ======   ==    ==     >>> ";
	gotoxy(3, 8); cout << "  =        = ==   =====        ==      >>>   ";
	gotoxy(3, 9); cout << "  ==   ==  = ==  =====        ==     >>>     ";
	gotoxy(3, 10); cout << "   =====   = == =...= ===    ==    >..>      ";
}

void Game::Options_Menu(){
	road.clear();
	road.show();
	Out_Name();
	string di[5] = { "*    ","**   ","***  ","**** ","*****" };
	gotoxy(15, 20);
	cout << "[High Score]" << endl;
	gotoxy(15, 25);
	cout << "[Choose Player]" << endl;
	gotoxy(15, 30);
	cout << "[Difficult: " <<di[Enemy::hard]<< " ]"<< endl;
	gotoxy(15, 35);
	cout << "[Back]" << endl;
}

void Game::Choose_Difficult(){
	string di[5] = { "*    ","**   ","***  ","**** ","*****" };
	char input = '_';
	do {
		gotoxy(15, 30);
		cout << "[Difficult: " << di[Enemy::hard] << " ]" << endl;
		input = _getch();
		switch (input) {
		case 'd': case 'D':
			Enemy::hard = min(4, Enemy::hard+1);
			break;
		case 'a': case 'A':
			Enemy::hard = max(0, Enemy::hard-1);
			break;
		}
	} while (input != 13);
	Options();
}


void Game::Out_HighScore() {
	road.clear();
	road.show();
	Out_Name();
	gotoxy(15, 16);
	cout << "~~~!!High Score!!~~~" << endl;
	int pos = 20;
	int rank = 1;
	int n = HighScore_List.size();
	for (int i = 0; i<n; ++i) {
		gotoxy(10, pos);
		cout << rank << ":        " << (i < 9 ? " ":"")<< HighScore_List[i];
		rank++;
		pos += 2;
	}
	gotoxy(15, 44);
	cout << "Enter a charactor to go [BACK]";
	_getch();
	Options();
}

void Game::setPlayer_Shape(int type) {
	road.clear();
	road.show();
	Out_Name();
	player.shape.get_player_shape(type);
	player.shape_type = type;
	gotoxy(12, 18);
	cout << "~~------- !Choose! -------~~";
	gotoxy(23, 30); cout << '|' << player.shape.get_1() << '|';
	gotoxy(23, 31); cout << '|' << player.shape.get_2() << '|';
	gotoxy(23, 32); cout << '|' << player.shape.get_3() << '|';
	gotoxy(15, 44);
	cout << "Enter a charactor to go [BACK]";
	_getch();
	Options();

}

void Game::die_Menu() {
	road.clear();
	road.show();
	Out_Name();
	PutScore();
	highScore = max(highScore, Score);
	gotoxy(5, 18);
	cout << "GAME OVER!!!";
	gotoxy(5, 20);
	cout << "Your score: " << Score;
	gotoxy(5, 22);
	cout << "High Score: " << highScore;
	gotoxy(10, 25);
	cout << "Enter a charactor to play again";
	_getch();
	Game newGame;
	int hS = highScore;
	vector<int> hSL = HighScore_List;
	*this = newGame;
	highScore = hS;
	HighScore_List = hSL;
	running();
}

int Game::Pause_Menu() {
	road.clear();
	road.show();
	Out_Name();
	gotoxy(15, 20);
	cout << "[RESUME]" << endl;
	gotoxy(15, 25);
	cout << "[EXIT]" << endl;
	int curr = 20;
	char input = '_';
	do {
		gotoxy(10, curr);
		cout << ">>>";
		input = _getch();
		gotoxy(10, curr);
		cout << "   ";
		switch (input) {
		case 's': case 'S':
			curr = min(25, curr + 5);
			break;
		case 'w': case 'W':
			curr = max(20, curr - 5);
			break;
		case '1':
			curr = 20;
			break;
		case '2':
			curr = 25;
			break;
		}
	} while (input != 13); //go go go

	return curr / 5 - 4;
}

int Game::Load_Menu() {
	char input;
	int curr = 20;
	road.clear();
	road.show();
	Out_Name();
	Out_Control();
	gotoxy(12, 2);
	cout << "~~------- !GOAL! -------~~";
	gotoxy(15, 20);
	cout << "[START GAME]" << endl;
	gotoxy(15, 25);
	cout << "[LOAD GAME]" << endl;
	gotoxy(15, 30);
	cout << "[OPTIONS]" << endl;
	gotoxy(15, 35);
	cout << "[QUIT]" << endl;
	gotoxy(30, 15);
	cout << "Level: " << level;
	gotoxy(30, 17);
	cout << "High Score: ";
	gotoxy(34, 19);
	cout << highScore;
	do {
		gotoxy(10, curr);
		cout << ">>>";
		input = _getch();
		gotoxy(10, curr);
		cout << "   ";
		switch (input) {
		case 's': case 'S':
			curr = min(35, curr + 5);
			break;
		case 'w': case 'W':
			curr = max(20, curr - 5);
			break;
		case '1':
			curr = 20;
			break;
		case '2':
			curr = 25;
			break;
		case '3':
			curr = 30;
			break;
		case '4':
			curr = 35;
			break;
		}
	} while (input != 13); //go go go

	return curr / 5 - 4;
}

void Game::Choose_Player_Menu(){
	road.clear();
	road.show();
	Out_Name();
	gotoxy(12, 16);
	cout << "~~------- !Choose! -------~~";
	int curr = 18;
	Shape tmp;
	for (int i = 0; i<MST; ++i) {
		tmp.get_player_shape(i);
		gotoxy(23, curr);
		cout << '|' << tmp.get_1() << '|';
		gotoxy(23, curr + 1);
		cout << '|' << tmp.get_2() << '|';
		gotoxy(23, curr + 2);
		cout << '|' << tmp.get_3() << '|';
		curr += 4;
	}

	gotoxy(23, curr + 1);
	cout << "[BACK]" << endl;

}