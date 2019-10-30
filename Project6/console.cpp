#include <iostream>
#include <Windows.h>
#include "console.h"

Console::Console(unsigned width, unsigned height)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT r;
	COORD c;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		throw runtime_error("You must be attached to a human.");

	r.Left = 0;
	r.Top = 0;
	r.Right = width - 1;
	r.Bottom = height - 1;
	SetConsoleWindowInfo(hConsole, TRUE, &r);

	c.X = width;
	c.Y = height;
	SetConsoleScreenBufferSize(hConsole, c);
}

// Description: Clears the screen
void Console::clear()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	DWORD dwConSize;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);

};

// Precondition: two non-negative integer parameters for the x and y are provided
// Description: Moves the cursor to x, y in console window, i.e. x=left\right y=top\bottom
// Example: gotoXY(10, 10) moves the cursor to those coordinates
//			gotoXY(0, 10) moves the cursor to those coordinates
//			gotoXY(-1, 0), gotoXY(0, -1) and gotoXY(-1, -1) throws an exception
void Console::gotoXY(int x, int y)
{
	if (x<0 || y<0)
	{
		std::cout << "Coordinates cannot be less than zero." << std::endl;
		exit(1);
	}
	else
	{
		COORD point;
		point.X = x;
		point.Y = y;
		SetConsoleCursorPosition(hConsole, point);
	}
};

void Console::setColour(COLOUR foreground, COLOUR background)
{
	int colour = background * 16 + foreground;
	SetConsoleTextAttribute(hConsole, colour);
};
