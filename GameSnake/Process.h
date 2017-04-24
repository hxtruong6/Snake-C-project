#pragma once
#include "Console.h"
#include <Windows.h>
#include <vector>
#include <conio.h>
#define MSSV 7

#pragma pack(1)

using namespace std;

struct InfoSnake
{
	COORD pos;
	char cSnake;
	int id;
};
enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
class Level
{
private: int scoreNextLevel;
public:	Level();
		static  int level;
		int GetSpeed(int level);
		int GetScoreNextLevel(int level);

};
class Game : Console
{
private:
	static Console console;
	
	static COORD Food;
	static SHORT columns, rows;
	
	static COORD CreateFood();
	static bool SuitableFood(COORD coord);
	static int xGate, yGate;
	
	
	static void Initialize();
public:
	Game();
	static vector<InfoSnake> snake;
	static eDirection dir;
	static COORD stateSnake;


	static Level levelGame; //level of game
	static bool overGame;
	static void KeyBoard();
	static void LogicGame();
	static void Draw();
	static void ResetData();
	static void InitiSnake();
	static void CreateGate();
	static bool CheckGate(int x, int y);
	//static void GameLevel();
};
