#pragma once
#include <iostream>
#include <Windows.h>

#define Height 600
#define Width 900
#pragma pack(1)
using namespace std;

class Console
{
private: 
	SHORT colums, rows;
	void FixConsoleWindow();
public:
	Console();
	
	void CreateBoard();
	void SetCoordinate(COORD coord);	
	void SetColor(int x);
	void GetStateOfConsole(SHORT & columns, SHORT & rows);
};