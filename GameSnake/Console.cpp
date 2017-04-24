#include "Console.h"

Console::Console()
{
	FixConsoleWindow();
	GetStateOfConsole(colums, rows);
}

void Console::FixConsoleWindow()
{

	HWND consoleWindow = GetConsoleWindow();

	//get current size of window
	int currentWidth = GetSystemMetrics(SM_CXSCREEN);
	int currentHeight = GetSystemMetrics(SM_CYSCREEN);

	int NewWidth = (currentWidth - Width) / 2;		//--- Used as a parameter to center the console window horizontally (MoveWindows int x)
	int NewHeight = ((currentHeight - Height) / 2);		//--- Used as a parameter to center the console window vertically (MoveWindows int y)

														//MoveWindow(window_handle, x, y, width, height, redraw_window); 
	MoveWindow(consoleWindow, NewWidth, NewHeight, Width, Height, TRUE);

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

}

void Console::CreateBoard()
{
	COORD coord;

	for (SHORT i = 0; i < colums - 30; i++)
	{
		coord = { i ,0 };
		SetCoordinate(coord);
		cout << "#";

		coord = { i,rows - 10 };
		SetCoordinate(coord);
		cout << "#";
	}

	for (SHORT i = 0; i <= rows - 10; i++)
	{
		coord = { 0, i };
		SetCoordinate(coord);
		cout << "#";

		coord = { colums - 30,i };
		SetCoordinate(coord);
		cout << "#";
	}
	cout << endl;
}

void Console::SetCoordinate(COORD coord)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::GetStateOfConsole(SHORT & columns, SHORT & rows)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Console::SetColor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}
