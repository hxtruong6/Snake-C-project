#pragma once
#include <string>
#include <Windows.h>
#include <fstream>
#include "Console.h"
#include "Process.h"

using namespace std;


class StartGame : public Level
{
private:
	static Console console;
	static string name;	
	//static int level;

	static int choose;// user choose new/ load/ exit;
public:
	StartGame();
	static int length;
	static int score;

	void SetInfoUser(int level, int length, string name);
	void GetInfoFromUser();
	void GetInfoFromFile();
	void SaveInfoGame();
	void PrintInfo();
	void UpdateScore(int score, int length);
	int GetLevelForUser();
	string GetName();
	static int GetChoose();
};

