#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//This algorithm is followed by Quine-McCluskey method


class TuToiTieu
{
private:
	string _bin;
	int _index;	//So luong chu so 1 trong _bin
	int _tick;
	void bin2Index();
public:
	TuToiTieu();
	TuToiTieu(const TuToiTieu &n);
	TuToiTieu(const string &bin, const int &index, const int &tick);
	void setBin(string bin);
	string getBin() { return _bin; }
	int getIndex() { return _index; }
	void setTick() { _tick = 1; }
	int getTick() { return _tick; }

	void output();
	int Bin2Dec();	//Chuyen binary sang decimal
	int Str2integer();
	bool flag(const TuToiTieu&n);//2 chuoi bin co 1 ki tu khac
	TuToiTieu replace(const TuToiTieu&n);//Thay the: vidu: 0011 va 0010 thanh 001-
	TuToiTieu& operator= (const TuToiTieu &n);
	~TuToiTieu();
};

class LIST
{
private:
	TuToiTieu *_data;
	int _n;
public:
	LIST();
	LIST(const LIST &n);
	LIST(TuToiTieu *a, int n);
	vector<string> tokenizeInputStr(string str);
	void parseStr(const vector<string> &str);
	void sort();
	void output();
	void createData();
	bool vector_(vector<TuToiTieu> kt, TuToiTieu x);// Xem x._bin co trong vector kt khong 
	LIST paste();
	~LIST();
};




