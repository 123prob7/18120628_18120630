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
	Vector temp = Vector();
	if (_n != x._n) 
		return temp;
	temp = Vector(x._n,0);
	for (int i = 0; i < _n; i++)
		temp._data[i] = _data[i] + x._data[i];
	return temp;
}

Vector Vector::operator* (float k)
{
	for (int i = 0; i < _n; i++)
		_data[i] *= k;
	return *this;
}

void Vector::input()
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

void Vector::output()
{
	for (int i = 0; i < _n; i++)
		cout << "\t" << _data[i];
	cout << endl;
}

