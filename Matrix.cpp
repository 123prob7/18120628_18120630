#include "Matrix.h"


Matrix::Matrix()
{
	_a = NULL;
	_m = 0;
	_n = 0;
}

Matrix::~Matrix()
{
	for (int i = 0; i < _m; i++)
		delete[] _a[i];
	delete[] _a;
}

Matrix::Matrix(const Matrix &x)
{
	_m = x._m;
	_n = x._n;
	_a = new float *[x._m];
	for (int i = 0; i < x._m; i++)
		_a[i] = new float[x._n];
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
		_a[i][j] = x._a[i][j];
}

Matrix::Matrix(float **a, int m, int n)
{
	_m = m;
	_n = n;
	_a = new float *[m];
	for (int i = 0; i < m; i++)
		_a[i] = new float[n];
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
		_a[i][j] = a[i][j];
}

void Matrix::_input()
{
	cout << "Nhap ma tran co m dong, n cot:" << endl;
	cout << "m = "; cin >> _m;
	cout << "n = "; cin >> _n;
	_a = new float*[_m];
	for (int i = 0; i < _m; i++)
		_a[i] = new float[_n];
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
	{
		cout << "a[" << i << "][" << j << "] = ";
		cin >> _a[i][j];
	}
}

void Matrix::_output()
{
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
		cout << "a[" << i << "][" << j << "] = " << _a[i][j] << endl;
}

Matrix& Matrix::operator=(const Matrix &x)
{
	if (_a != NULL) {
		for (int i = 0; i < _m; i++)
			delete[] _a[i];
		delete[] _a;
	}
	_m = x._m;
	_n = x._n;
	_a = new float *[x._m];
	for (int i = 0; i < x._m; i++)
		_a[i] = new float[x._n];
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
		_a[i][j] = x._a[i][j];
	return *this;
}



float Matrix::_determinant()
{
	//Determinant of square matrix. It's not suitable for non square one.
	return DetOfMatrix(_a, _n);
}


float DetOfMatrix(float **a, int n)
{
	if (n == 1) return a[0][0];
	if (n == 2){
		cout << a[0][0] << a[1][1] << a[0][1] << a[1][0] << endl;
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	if (n > 2)
	{
		float det = 0;
		for (int j = 0; j < n; j++) //Duyet qua tung cot cua mang
		{

			float **temp;	//mang tam loai bo dong 0 va cot 0
			temp = new float*[n - 1];
			for (int k = 0; k < n - 1; k++)
				temp[k] = new float[n - 1];


			for (int k = 0; k < n - 1; k++)
			for (int l = 0; l < n; l++)
			{
				if (l < j)
					temp[k][l] = a[1 + k][l];
				else if (l > j)
					temp[k][l - 1] = a[1 + k][l];
			}
			//if (n == 4) cout << a[0][j] << endl;
			if (j % 2 == 0)
				det += a[0][j] * DetOfMatrix(temp, n - 1);
			else if (j % 2 != 0)
				det -= a[0][j] * DetOfMatrix(temp, n - 1);
			
			for (int g = 0; g < n - 1; g++)
				delete[] temp[g];
			delete[] temp;
		}
		return det;
	}
}

