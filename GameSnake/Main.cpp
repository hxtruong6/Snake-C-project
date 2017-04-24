#include <iostream>
#include "Console.h"
#include "Information.h"
#include "Process.h"


using namespace std;
void NewGame(StartGame start)
{
	Console console;
	Game gameRunning;
	start.GetInfoFromUser();
	gameRunning.levelGame.level= start.GetLevelForUser();
	int speed= gameRunning.levelGame.GetSpeed(gameRunning.levelGame.level);
	start.score = 0;
	
	
	system("color a");
	console.CreateBoard();
	gameRunning.ResetData();
	while (true)
	{
		gameRunning.overGame = false;
		start.length = gameRunning.snake.size();
		start.SetInfoUser(gameRunning.levelGame.level, start.length, start.GetName());
		gameRunning.stateSnake = gameRunning.snake.at(gameRunning.snake.size() - 1).pos;
		gameRunning.dir = RIGHT;
		gameRunning.InitiSnake();

		bool nextLevel = false;
		while (!gameRunning.overGame)
		{
			gameRunning.KeyBoard();
			gameRunning.stateSnake = gameRunning.snake.at(gameRunning.snake.size() - 1).pos;
			gameRunning.LogicGame();			
			gameRunning.Draw();

			if (start.length == gameRunning.snake.size() - 1)
			{
				start.score += 10;
				start.length++;
			}
			start.PrintInfo();
			if (!nextLevel && start.score >= start.GetScoreNextLevel(gameRunning.levelGame.level) )
			{
				//code
				start.level = ++gameRunning.levelGame.level;
				gameRunning.CreateGate();
				nextLevel = true;
			}
			else if (nextLevel&& gameRunning.CheckGate(gameRunning.snake.at(gameRunning.snake.size()-1).pos.X, gameRunning.snake.at(gameRunning.snake.size() - 1).pos.Y))
			{
				gameRunning.overGame = true;
			}
			Sleep(speed);
		}
	}
}

int main()
{
	system("cls");
	StartGame start;
	int choose = start.GetChoose();
	switch (choose)
	{
	case 1:
	{
		NewGame(start);
		break;
	}
	case 2:
	{
		//load game save from file
		break;
	}
	case 3:
	{
		//exit game
		break;
	}
	default:
		break;
	}
	return 0;
}