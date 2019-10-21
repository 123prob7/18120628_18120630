#include "Menu.h"


Menu::Menu()
{
	_key = 0;
	_a[0] = "1. Tim tat ca cong thuc da thuc toi tieu cua ham Bool";
	_a[1] = "2. Lam phep toan tren vector";
	_a[2] = "3. Lam phep toan tren ma tran";
	_a[3] = "4. Thoat";
	_a[4] = "1. Phep toan cong 2 vector";
	_a[5] = "2. Phep toan nhan vector voi 1 so alpha";
	_a[6] = "1. Tim dinh thuc cua ma tran";
	_a[7] = "2. Nghich dao ma tran";
	_a[8] = "3. Tich 2 ma tran";
	_a[9] = "4. Tim hang cua ma tran";
	_a[10] = "5. He phuong trinh tuyen tinh";
	_a[11] = "Quay lai (<-)";
}


Menu::~Menu()
{
}

void Menu::_drawMenu()
{
	do {
		clrscr();
		Nocursortype();
		gotoXY(0, 0);
		cout << "--------Ung dung lam toan co ban TRR va DSTT--------" << endl;
		cout << "Chon 1 trong cac thao tac sau" << endl;
		for (int i = 0; i < 4; i++)
			cout << _a[i] << endl;
		char c;
		do {
			fflush(stdin);
			c = _getch();
		} while (c < 49 || c > 52);
		_key = c - 48;

		switch (_key)
		{
		case 1:
		{
				  clrscr();
				  cursortype();
				  gotoXY(0, 0);
				  cout << "-------Tim tat ca cac cong thuc da thuc toi tieu-------" << endl;
				  cout << "Nhap vao chuoi input: f(w, x, y, z) = ";
				  string s;
				  fflush(stdin);
				  getline(cin, s);
				  LIST a;
				  a.parseStr(a.tokenizeInputStr(s));
				  a.createData();
				  a.sort();
				  LIST b;
				  b.vectorToList(solvePrimeImplicants(a));
				  b.output();
				  cout << "Nhan phim bat ky de quay lai";
				  Nocursortype();
				  _getch();
				  _key = 0;
				  break;
		}
		case 2:
		{
				  char c2;
				  do {
					  clrscr();
					  gotoXY(0, 0);
					  cout << "---------Lam toan tren vector---------" << endl;
					  cout << _a[4] << endl << _a[5] << endl << _a[11] << endl;

					  do {
						  fflush(stdin);
						  c2 = _getch();
					  } while (c2 != 49 && c2 != 50 && c2 != 8);

					  if (c2 == 49)
					  {
						  Vector a, b;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "----------Phep toan cong 2 vector----------" << endl << "Nhap 2 vector:" << endl;
						  a.input();
						  b.input();
						  cout << "Hai vector vua nhap:" << endl;
						  a.output();
						  b.output();
						  Vector c;
						  cout << "\nTong 2 vector:\n";
						  c = a + b;
						  c.output();
						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
					  else if (c2 == 50)
					  {
						  Vector a;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "-------Nhan vector voi 1 so alpha-------" << endl << "Nhap vector:" << endl;
						  a.input();
						  cout << "Nhap hang so alpha: k = ";
						  float k;
						  cin >> k;
						  cout << "Ket qua:" << endl;
						  Vector b;
						  b = a*k;
						  b.output();
						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
				  } while (c2 != 8);
				  if (c2 == 8) _key = 0;
				  break;
		}
		case 3:
		{
				  char c2;
				  do {
					  clrscr();
					  gotoXY(0, 0);
					  cout << "---------Lam toan tren ma tran---------" << endl;
					  for (int i = 6; i < 12; i++)
						  cout << _a[i] << endl;

					  do {
						  fflush(stdin);
						  c2 = _getch();
					  } while ((c2 < 49 || c2 > 53) && c2 != 8);

					  if (c2 == 49)
					  {
						  Matrix a;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "----------Tim dinh thuc cua ma tran----------" << endl << "Nhap ma tran:" << endl;
						  a.input();
						  cout << "det(a) = " << a.determinant() << endl;
						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
					  else if (c2 == 50)
					  {
						  Matrix a;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "----------Nghich dao cua ma tran----------" << endl << "Nhap ma tran:" << endl;
						  //a._input();
						  cout << "Ma tran nghich dao:" << endl;


						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
					  else if (c2 == 51)
					  {
						  Matrix a, b;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "----------Tich 2 ma tran----------" << endl << "Nhap ma tran:" << endl;
						  a.input();
						  b.input();
						  cout << "Ket qua:" << endl;
						  Matrix c;
						  c = a *b;
						  c.output();

						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
					  else if (c2 == 52)
					  {
						  Matrix a;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "----------Hang cua ma tran----------" << endl << "Nhap ma tran:" << endl;
						  a.input();
						  cout << "r(a) = " << a.rank() << endl;

						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
					  else if (c2 == 53)
					  {
						  Matrix a;
						  clrscr();
						  gotoXY(0, 0);
						  cursortype();
						  cout << "----------He phuong trinh tuyen tinh----------" << endl << "Nhap ma tran he so cua nghiem X:" << endl;
						  a.input();
						  Matrix b;
						  cout << "Nhap ma tran ket qua:" << endl;
						  b.input();
						  while (a.MatrixEquation(b) == 0)
						  {
							  cout << "\nDu lieu nhap khong khop!\n";
							  b.~Matrix();
							  b.input();
						  }
						  cout << "Nhan phim bat ky de quay lai";
						  Nocursortype();
						  _getch();
					  }
				  } while (c2 != 8);
				  if (c2 == 8) _key = 0;
				  break;
		}
		case 4:
		{
				  clrscr();
				  cursortype();
				  gotoXY(0, 0);
				  cout << "Thoat...";
				  return;
				  break;
		}
		case 0:
			_key = 0;
			break;
		}
	} while (_key == 0);
}



void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void cursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
