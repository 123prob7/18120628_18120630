#pragma once
#include "Matrix.h"
#include "Vector.h"
#include "Karnaugh.h"
#include <Windows.h>
#include <conio.h>

class Menu
{
private:
	int _key;
	string _a[12];
public:
	Menu();
	~Menu();
	void _drawMenu();
};

void clrscr();
void gotoXY(int column, int line);
void Nocursortype();
void cursortype();
