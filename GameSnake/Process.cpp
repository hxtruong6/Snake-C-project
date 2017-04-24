#include "Process.h"
#include <ctime>

const string charSnake = "1612899";

Game::Game()
{
	Initialize();
}

void Game::ResetData()
{
	InfoSnake info;
	for (int i = 0; i < 7; i++)
	{
		info.id = i % MSSV;
		info.cSnake = charSnake[info.id];
		info.pos = { (SHORT)i + 1,1 };
		snake.push_back(info);
	}
	//Food = CreateFood();
}

void Game::InitiSnake()
{
	SHORT k = 1;
	for (int i = 0; i < snake.size(); i++)
	{
		if (i + 1 >= columns)
			k++;
		if (k % 2 != 0)
			snake[i].pos = { (SHORT)i + 1, k };
		else
			snake[i].pos = { (SHORT)(columns - ((i + 1) % columns + 1)), k };
		console.SetCoordinate(snake[i].pos);
		cout << snake[i].cSnake;
	}
	Food = CreateFood();

}

void Game::CreateGate()
{
	srand(time(NULL));
	xGate = columns;
	yGate = rand() % (rows - 1) + 1;
	console.SetCoordinate({(SHORT) xGate, (SHORT)yGate });
	console.SetColor(15);
	cout << "$";
}

bool Game::CheckGate(int x, int y)
{
	return (xGate == x) && (yGate = y);
}



COORD Game::CreateFood()
{
	COORD coord;

	do
	{
		srand(time(NULL));
		coord = { rand() % (columns - 1) + 1, rand() % (rows - 1) + 1 };
		console.SetCoordinate(coord);
	} while (!SuitableFood(coord));
	cout << "0";
	return coord;

}

bool Game::SuitableFood(COORD coord)
{
	for (auto i : snake)
	{
		if (i.pos.X == coord.X && i.pos.Y == coord.Y)
		{
			return false;
		}
	}
	return true;
	return false;
}

void Game::KeyBoard()
{
	if (kbhit())
	{
		char c = getch();
		switch (c)
		{
		case 'a':
		{
			if (snake.at(snake.size() - 1).pos.X != snake.at(snake.size() - 2).pos.X + 1 && dir != LEFT)
			{
				dir = LEFT;

			}
			break;
		}

		case 'd':
		{
			if (snake.at(snake.size() - 1).pos.X != snake.at(snake.size() - 2).pos.X - 1 && dir != RIGHT)

			{
				dir = RIGHT;


			}
			break;
		}
		case 'w':
		{
			if (snake.at(snake.size() - 1).pos.Y != snake.at(snake.size() - 2).pos.Y + 1 && dir != UP)

			{
				dir = UP;

			}
			break;
		}
		case 's':
		{
			if (snake.at(snake.size() - 1).pos.Y != snake.at(snake.size() - 2).pos.Y - 1 && dir != DOWN)

			{
				dir = DOWN;

			}
			break;
		}
		}
	}
}

void Game::LogicGame()
{
	switch (dir)
	{
	case LEFT:
		stateSnake.X--;
		break;
	case RIGHT:
		stateSnake.X++;
		break;
	case UP:
		stateSnake.Y--;
		break;
	case DOWN:
		stateSnake.Y++;
		break;
	default:
		break;
	}
	//check snake go out
	if (stateSnake.X < 1 || stateSnake.X >= columns || stateSnake.Y < 1 || stateSnake.Y >= rows)
	{
		overGame = true;
		return;
	}
	//check snake eat body
	for (int i = 1; i < snake.size(); i++)
	{
		if (snake[i].pos.X == stateSnake.X && snake[i].pos.Y == stateSnake.Y)
		{
			overGame = true;
			return;
		}
	}


	if (stateSnake.X == Food.X && stateSnake.Y == Food.Y)
	{
		InfoSnake temp;
		temp.id = (snake.size()) % MSSV;
		temp.pos = stateSnake;
		temp.cSnake = charSnake[temp.id];

		snake.push_back(temp);

		Food = CreateFood();
	}
	else if (dir != STOP)
	{
		console.SetCoordinate(snake[0].pos);
		cout << " ";
		for (int i = 0; i < snake.size() - 1; i++)
		{
			snake[i].pos = snake[i + 1].pos;
		}
		snake[snake.size() - 1].pos = stateSnake;
	}
}

void Game::Draw()
{
	for (auto i : snake)
	{
		console.SetCoordinate(i.pos);
		console.SetColor(i.id + 8); //set color
		cout << i.cSnake;
	}
}

/*void Game::GameLevel()
{
	overGame = false;
	stateSnake = snake.at(snake.size() - 1).pos;
	dir = RIGHT;
	while (!overGame)
	{
		KeyBoard();
		stateSnake = snake.at(snake.size() - 1).pos;
		LogicGame();
		Draw();
		Sleep(speed);
	}
}*/

void Game::Initialize()
{
	console.GetStateOfConsole(columns, rows);
	columns -= 30;
	rows -= 10;
}

Level::Level()
{

}

int Level::GetSpeed(int level)
{
	int res = 400;
	scoreNextLevel = 0;
	for (int i = 0; i < level; i++)
	{
		res -= (40 + 5 * i);
		scoreNextLevel += (100 + 50 * i);
	}
	return res;
}

int Level::GetScoreNextLevel(int level)
{
	return scoreNextLevel;
}
