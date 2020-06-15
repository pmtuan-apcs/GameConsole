#ifndef _Game_h_
#define _Game_h_
#include"Header.h"
#include"Player.h"
#include"Enemy.h"
#include"Road.h"
#include"Shape.h"
class Game{
public:
	void running();
	Game();

private:
	Player player;
	Enemy enemy[14];
	Road road;
	vector<int> HighScore_List;
	bool Game_Over;
	int level;
	int highScore;
	int Score;

	void level_UP();
	void Start();
	void Exit();

	bool Put2Road();
	void moving();
	void PutScore();
	void setPlayer_Shape(int type);
	void Player_move();

	void Out_Health();
	void Out_Score();
	void Out_Control();
	void Out_HighScore();

	bool Load_Game(string name);
	bool Save_Game(string name);
	void Pause_Game();

	void Light();

	void Options_Menu();
	void Choose_Player_Menu();
	int Pause_Menu();
	void Choose_Player();
	void Choose_Difficult();
	void Save();
	void Load();
	void Options();
	void Out_Name();
	void die_Menu();
	int Load_Menu();

};
#endif