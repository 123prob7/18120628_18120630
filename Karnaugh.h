#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <set>
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
	int operator==(const TuToiTieu &n);
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
	void removeDuplicates();
	int checkTick();
	vector<TuToiTieu> toVector();
	LIST vectorToList(const vector<TuToiTieu> &a);
	LIST& operator= (const LIST &n);
	int size() { return _n; }
	TuToiTieu& operator[](int i);
	int** createPrimeImplicantsTable(const LIST &a);
	set<set<int>> allMinSpawn(int** arr, const LIST &a);
	void getPossibleCombines(vector<set<int>> &petLogic, int level, set<int> prod, set<set<int>> &pComb);
	void displayBoolFunction(set<set<int>> minSpawns);
	~LIST();
};

vector<TuToiTieu> solvePrimeImplicants(LIST a);
string bintoNameOfVariable(string bin);


