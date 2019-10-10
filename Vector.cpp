#include "Vector.h"


Vector::Vector()
{
	_data = NULL;
	_n = 0;
}


Vector::~Vector()
{
	delete[] _data;
}

Vector::Vector(const Vector &x)
{
	_n = x._n;
	_data = new float[x._n];
	for (int i = 0; i < x._n; i++)
		_data[i] = x._data[i];
}

Vector::Vector(float *v, int n)
{
	_n = n;
	_data = new float[n];
	for (int i = 0; i < n; i++)
		_data[i] = v[i];
}

Vector::Vector(int n, float val)
{
	_n = n;
	_data = new float[_n];
	for (int i = 0; i < _n; i++)
		_data[i] = val;
}

Vector& Vector::operator= (const Vector &x)
{
	if (_data != NULL) delete[] _data;
	_n = x._n;
	_data = new float[x._n];
	for (int i = 0; i < x._n; i++)
		_data[i] = x._data[i];
	return *this;
}

Vector Vector::operator+ (const Vector &x)
{
	if (_n != x._n) return { NULL, 0 };
	for (int i = 0; i < _n; i++)
		_data[i] += x._data[i];
	return *this;
}

Vector Vector::operator* (int k)
{
	for (int i = 0; i < _n; i++)
		_data[i] *= k;
	return *this;
}

void Vector::_input()
{
	cout << "\nNhap vao so luong phan tu: n = ";
	cin >> _n;
	_data = new float[_n];
	for (int i = 0; i < _n; i++)
	{
		cout << "Phan tu vector[" << i << "] = ";
		cin >> _data[i];
	}
}

void Vector::_output()
{
	for (int i = 0; i < _n; i++)
		cout << "\t" << _data[i];
	cout << endl;
}

