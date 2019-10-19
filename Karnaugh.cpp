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
	_bin = bin;
	bin2Index();
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

void TuToiTieu::bin2Index()
{
	int count = 0;
	for (int i = 0; i < _bin.length(); i++)
	if (_bin[i] == '1')
		count++;
	_index = count;
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
	_data = new TuToiTieu[size];
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
	if (_data[i].getIndex() == _data[j].getIndex() && _data[i].Bin2Dec() > _data[j].Bin2Dec())
	{
		TuToiTieu temp = _data[i];
		_data[i] = _data[j];
		_data[j] = temp;
	}
}

void LIST::createData()
{
	TuToiTieu *result;
	int size = 0;
	for (int i = 0; i < _n; i++){
		int dem = 0;
		for (int j = 0; j < _data[i].getBin().length(); j++)
		{
			if (_data[i].getBin()[j] == '-')
				dem++;
		}
		if (dem == 3)
			size += 8;
		else if (dem == 2)
			size += 4;
		else if (dem == 1)
			size += 2;
		else if (dem == 0)
			size++;
	}
	result = new TuToiTieu[size];
	int index = 0;

	for (int i = 0; i < _n; i++){
		int dem = 0;
		for (int j = 0; j < _data[i].getBin().length(); j++)
		{
			if (_data[i].getBin()[j] == '-')
				dem++;
		}

		if (dem == 0)
			result[index++].setBin(_data[i].getBin());
		else if (dem == 1)
		{
			string temp = _data[i].getBin();
			for (int g = 0; g < 2; g++)
			for (int h = 0; h < temp.length(); h++)
			if (temp[h] == '-')
			{
				temp[h] = g + 48;
				result[index++].setBin(temp);
				temp[h] = '-';
				break;
			}
		}
		else if (dem == 2)
		{
			string temp = _data[i].getBin();
			for (int g = 0; g < 2; g++)
			for (int k = 0; k < 2; k++)
			{
				int pre_h = 0;
				int key = 0;
				for (int h = 0; h < temp.length(); h++)
				{
					if (key == 0 && temp[h] == '-')
					{
						pre_h = h;
						key++;
					}
					else if (key == 1 && temp[h] == '-')
					{
						temp[pre_h] = g + 48;
						temp[h] = k + 48;
						result[index++].setBin(temp);
						temp[pre_h] = '-';
						temp[h] = '-';
						break;
					}
				}
			}
		}
		else if (dem == 3)
		{
			string temp = _data[i].getBin();
			for (int g = 0; g < 2; g++)
			for (int l = 0; l < 2; l++)
			for (int k = 0; k < 2; k++)
			{
				int pre_h1 = 0;
				int pre_h2 = 0;
				int key = 0;
				for (int h = 0; h < temp.length(); h++)
				{
					if (key == 0 && temp[h] == '-')
					{
						pre_h1 = h;
						key++;
					}
					else if (key == 1 && temp[h] == '-')
					{
						pre_h2 = h;
						key++;
					}
					else if (key == 2 && temp[h] == '-')
					{
						temp[pre_h1] = g + 48;
						temp[pre_h2] = l + 48;
						temp[h] = k + 48;
						result[index++].setBin(temp);
						temp[pre_h1] = '-';
						temp[pre_h2] = '-';
						temp[h] = '-';
						break;
					}
				}
			}
		}
	}
	_n = size;
	_data = result;
}

// ===============================




