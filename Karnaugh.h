#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//This algorithm is followed by Quine-McCluskey method


class Chain
{
	vector<int> _bin;	//Binary rotation	, Example: 0000, 1010
	int _index;	//Index							0,	2
	int _dec;	//Decimal value					0,	10
public:
	Chain();
	Chain(const Chain &n) { _bin = n._bin; _index = n._index; _dec = n._dec; }
	Chain(vector<int> bin, int index, int dec) {_bin = bin; _index = index; _dec = dec; }
	void parseString(string s);
	void parseNumber(int n);

	~Chain();
};


int Vec2Num(vector<int> x);
int Bin2Dec(int n);	//Chuyen binary sang decimal
int Bin2Index(int n);	//Chuyen binary sang index value
int Dec2Bin(int n);