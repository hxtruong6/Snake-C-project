#include "Information.h"


void StartGame::PrintInfo()
{
	SHORT col, row;
	console.GetStateOfConsole(col, row);
	SHORT y = row / 2 - 10;
	SHORT x = col - 25;

	console.SetCoordinate({ x,y });
	console.SetColor(10);
	cout << "Hello: " << name << endl;

	console.SetColor(14);
	console.SetCoordinate({ x,y + 1 });
	cout << "Have a good time!!!" << endl;

	console.SetColor(12);
	console.SetCoordinate({ x,y + 2 });
	cout << "Level: " << level << endl;



	console.SetColor(8);
	console.SetCoordinate({ x,y + 3 });
	cout << "Score next level: " << GetScoreNextLevel(level) << endl;


	console.SetColor(11);
	console.SetCoordinate({ x,y + 4 });
	cout << "Length: " << length << endl;

	console.SetCoordinate({ x,y + 5 });
	cout << "Score: " << score << endl;
}

void StartGame::UpdateScore(int score, int length) // ? eat big food 
{
	this->score = score + 10;
	this->length = length + 1;
}


int StartGame::GetLevelForUser()
{
	return level;
}

string StartGame::GetName()
{
	return name;
}

int StartGame::GetChoose()
{
	console.SetCoordinate({ 5,5 });
	console.SetColor(9);
	cout << "Game Snake Version on console!!" << endl;
	console.SetColor(10);
	cout << "1. New game" << endl;
	cout << "2. Game save" << endl;
	cout << "3. Exit" << endl;

	console.SetColor(8);

	try
	{
		cout << "Please enter your choose(1/2/3): ";
		cin >> choose;
		if (choose < 1 || choose>3)
			throw  "Please enter 1, 2 or 3";
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return choose;
}

StartGame::StartGame()
{

}

void StartGame::SetInfoUser(int level, int length, string name)
{
	this->level = level;
	this->length = length;
	this->name = name;
}

void StartGame::GetInfoFromUser()
{
	SHORT col, row;
	console.GetStateOfConsole(col, row);
	SHORT y = row / 2;
	SHORT x = col / 2;
	console.SetCoordinate({ x - 35,y - 10 });

	console.SetColor(12);
	cout << "Please enter your name: ";

	string temp;
	cin >> ws; getline(cin, temp);
	name = temp;

	cout << endl;

	int delay = 40;
	console.SetColor(11);
	Sleep(delay); cout << "*** ";
	Sleep(delay); cout << "Welcome ";
	Sleep(delay); cout << name;
	Sleep(delay); cout << " go ";
	Sleep(delay); cout << "to ";
	Sleep(delay); cout << "game ";
	Sleep(delay); cout << "Snake ";
	Sleep(delay); cout << "on ";
	Sleep(delay); cout << "console";
	Sleep(delay); cout << "!!! ";
	Sleep(delay); cout << "***" << endl;

	console.SetColor(14);
	cout << "* I hope that this game will make you feel happy *" << endl;
	console.SetColor(8);
	cout << "                             Design by Xuan Truong" << endl;
	Sleep(delay + 20);

	console.SetColor(8);
	cout << "Choose your level(1->8): ";
	cin >> level;
}

void StartGame::GetInfoFromFile()
{
	//file data
	//name
	//score
	//level
	//length
	ifstream fi("GameData.txt");
	if (fi)
	{
		getline(fi, name);
		cin >> score >> level >> length;
	}
	fi.close();
}

void StartGame::SaveInfoGame()
{
	ofstream fo("GameData.txt");
	fo.clear();
	cout << name << endl << score << level << length << endl;
	fo.close();
}
