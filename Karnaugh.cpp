#include "Karnaugh.h"

// ========================
// Class Tu toi tieu
// 4 variables only

TuToiTieu::TuToiTieu()
{
	_bin = "0000";
	_index = 0;
}

TuToiTieu::~TuToiTieu()
{
}

TuToiTieu::TuToiTieu(const TuToiTieu &n)
{
	_bin = n._bin;
	_index = n._index;
}

TuToiTieu::TuToiTieu(const string &bin, const int &index)
{
	_bin = bin;
	_index = index;
}

void TuToiTieu::setBin(string bin)
{
	_index = 0;
	_bin = bin;
	for (int i = 0; i < bin.length(); i++)
	if (bin[i] == 49) // "1"
		_index++;
}

void TuToiTieu::output()
{
	cout << _bin;
}

int TuToiTieu::Bin2Dec()
{
	int result = 0;
	int num = Str2integer();
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

int TuToiTieu::Str2integer()
{
	int kq = 0;
	for (int i = 0; i < _bin.length(); i++)
		kq = kq * 10 + _bin[i] - 48;
	return kq;
}

TuToiTieu& TuToiTieu::operator=(const TuToiTieu &n)
{
	_bin = n._bin;
	_index = n._index;
	return *this;
}

// ==================


// ========================
// Class LIST

LIST::LIST()
{
	_data = NULL;
	_n = 0;
}

LIST::LIST(const LIST &n)
{
	_n = n._n;
	_data = new TuToiTieu[_n];
	for (int i = 0; i < _n; i++)
		_data[i] = n._data[i];
}

LIST::LIST(TuToiTieu *a, int n)
{
	_n = n;
	_data = new TuToiTieu[_n];
	for (int i = 0; i < _n; i++)
		_data[i] = a[i];
}

LIST::~LIST()
{
	delete[] _data;
}

vector<string> LIST::tokenizeInputStr(string str)
{
	vector<string> result;
	string temp;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != 43 && str[i] != 32) // "+" && (space)
			temp.push_back(str[i]);
		else{
			if (temp != "")
				result.push_back(temp);
			temp.clear();
		}
	}
	result.push_back(temp);
	return result;
}



void LIST::parseStr(const vector<string> &str)
{
	int size = str.size();
	_data = new TuToiTieu[size * 8];
	_n = size;
	for (int i = 0; i < size; i++)
	{
		string temp = "----";	// '-' tuong ung 2 gia tri 0 va 1
		for (int j = 0; j < str[i].length(); j++)
		{
			if (str[i][j] != 33) // "!"
			{
				char c = str[i][j];
				switch (c)
				{
				case 'w':
					if (j > 0 && str[i][j - 1] == 33)
					{
						temp[0] = '0';
						break;
					}
					temp[0] = '1';
					break;
				case 'x':
					if (j > 0 && str[i][j - 1] == 33)
					{
						temp[1] = '0';
						break;
					}
					temp[1] = '1';
					break;
				case 'y':
					if (j > 0 && str[i][j - 1] == 33)
					{
						temp[2] = '0';
						break;
					}
					temp[2] = '1';
					break;
				case 'z':
					if (j > 0 && str[i][j - 1] == 33)
					{
						temp[3] = '0';
						break;
					}
					temp[3] = '1';
					break;
				}
			}
		}
		_data[i].setBin(temp);
	}
	
}

void LIST::output()
{
	for (int i = 0; i < _n; i++)
	{
		_data[i].output();
		cout << " ";
	}
	cout << endl;
}

void LIST::sort()
{
	for (int i = 0; i < _n - 1; i++)
	for (int j = i + 1; j < _n; j++)
	if (_data[i].getIndex() > _data[j].getIndex())
	{
		TuToiTieu temp = _data[i];
		_data[i] = _data[j];
		_data[j] = temp;
	}
	for (int i = 0; i < _n - 1; i++)
	for (int j = i + 1; j < _n; j++)
	if (_data[i].Bin2Dec() > _data[j].Bin2Dec())
	{
		TuToiTieu temp = _data[i];
		_data[i] = _data[j];
		_data[j] = temp;
	}
}

// ===============================




