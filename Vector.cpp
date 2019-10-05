#include "Vector.h"


Vector::Vector()
{
	_v = NULL;
	_n = 0;
}


Vector::~Vector()
{
	delete[] _v;
}

Vector::Vector(const Vector &x)
{
	_n = x._n;
	_v = new float[x._n];
	for (int i = 0; i < x._n; i++)
		_v[i] = x._v[i];
}

Vector::Vector(float *v, int n)
{
	_n = n;
	_v = new float[n];
	for (int i = 0; i < n; i++)
		_v[i] = v[i];
}

Vector& Vector::operator= (const Vector &x)
{
	if (_v != NULL) delete[] _v;
	_n = x._n;
	_v = new float[x._n];
	for (int i = 0; i < x._n; i++)
		_v[i] = x._v[i];
	return *this;
}

Vector Vector::operator+ (const Vector &x)
{
	if (_n != x._n) return { NULL, 0 };
	for (int i = 0; i < _n; i++)
		_v[i] += x._v[i];
	return *this;
}

Vector Vector::operator* (int k)
{
	for (int i = 0; i < _n; i++)
		_v[i] *= k;
	return *this;
}

void Vector::_input()
{
	cout << "\nNhap vao so luong phan tu: n = ";
	cin >> _n;
	_v = new float[_n];
	for (int i = 0; i < _n; i++)
	{
		cout << "Phan tu v[" << i << "] = ";
		cin >> _v[i];
	}
}

void Vector::_output()
{
	for (int i = 0; i < _n; i++)
		cout << "v[" << i << "] = " << _v[i] << endl;
}

