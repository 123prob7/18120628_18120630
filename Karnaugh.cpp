#include "Karnaugh.h"

Chain::Chain()
{
	_bin = { 0, 0, 0, 0 };
	_index = 0;
	_dec = 0;
}

Chain::~Chain()
{
}

void Chain::parseString(string s)
{
	vector<int> result = { 0, 0, 0, 0 };
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
		if (s[i] == 33)
			i++;
		else if (97 <= s[i] && s[i] <= 100)
			result[s[i] - 97] = 1;
	}
	
}


int Vec2Num(vector<int> x)
{
	int result = 0;
	for (int i = 0; i < x.size(); i++)
		result += x[i] * pow(10, x.size() - 1);
	return result;
}

int Bin2Dec(int n)
{
	int result = 0;
	int num = n;
	int base = 1;
	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp /= 10;
		result += last_digit*base;
		base *= 2;
	}
	return result;
}

int Bin2Index(int n)
{
	int count = 0;
	while (n){
		if (n % 10) count++;
		n /= 10;
	}
	return count;
}

int Dec2Bin(int n)
{
	if (n == 0)
		return 0;
	return n % 2 + 10 * Dec2Bin(n / 2);
}
