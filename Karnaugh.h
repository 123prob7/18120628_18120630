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
	TuToiTieu& operator= (const TuToiTieu &n);
	int checkTick();
	int isCombined(const TuToiTieu &a);
	TuToiTieu combine(TuToiTieu &a);
	int isEssential(const TuToiTieu &a);
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
	int checkTick();
	vector<TuToiTieu> toVector();
	LIST vectorToList(const vector<TuToiTieu> &a);
	LIST& operator= (const LIST &n);
	int size() { return _n; }
	TuToiTieu& operator[](int i);
	int** chartRemoveRedundant(const LIST &a);
	~LIST();
};

vector<TuToiTieu> solvePrimeImplicants(LIST a);



