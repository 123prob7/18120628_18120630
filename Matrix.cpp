#include "Matrix.h"


Matrix::Matrix()
{
	_data = NULL;
	_m = 0;
	_n = 0;
}

Matrix::~Matrix()
{
	for (int i = 0; i < _m; i++)
		delete[] _data[i];
	delete[] _data;
}

Matrix::Matrix(const Matrix &x)
{
	_m = x._m;
	_n = x._n;
	_data = new float *[x._m];
	for (int i = 0; i < x._m; i++)
		_data[i] = new float[x._n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_data[i][j] = x._data[i][j];
}

Matrix::Matrix(float **a, int m, int n)
{
	_m = m;
	_n = n;
	_data = new float *[m];
	for (int i = 0; i < m; i++)
		_data[i] = new float[n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_data[i][j] = a[i][j];
}

Matrix::Matrix(int m, int n, float val)
{
	_m = m;
	_n = n;
	_data = new float *[m];
	for (int i = 0; i < m; i++)
		_data[i] = new float[n];
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_data[i][j] = val;
}

void Matrix::input()
{
	cout << "Nhap ma tran co m dong, n cot:" << endl;
	do {
		cout << "m = ";
		cin >> _m;
	} while (_m < 0);
	do{
		cout << "n = ";
		cin >> _n;
	} while (_n < 0);
	_data = new float*[_m];
	for (int i = 0; i < _m; i++)
		_data[i] = new float[_n];
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
	{
		cout << "a[" << i << "][" << j << "] = ";
		cin >> _data[i][j];
	}
}

void Matrix::output()
{
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
			cout << _data[i][j] << "\t";
		cout << endl;
	}
}

Matrix& Matrix::operator=(const Matrix &x)
{
	if (_data != NULL) {
		for (int i = 0; i < _m; i++)
			delete[] _data[i];
		delete[] _data;
	}
	_m = x._m;
	_n = x._n;
	_data = new float *[x._m];
	for (int i = 0; i < x._m; i++)
		_data[i] = new float[x._n];
	for (int i = 0; i < _m; i++)
	for (int j = 0; j < _n; j++)
		_data[i][j] = x._data[i][j];
	return *this;
}

float Matrix::determinant()
{
	//Determinant of square matrix. It's not suitable for non square one.
	if (_n == _m)
		return DetOfMatrix(_data, _n);
	else
		cout << "Khong thuc hien duoc phep tinh vi khong phai MT vuong";
}

Matrix Matrix::operator*(const Matrix & x)//Ma tran co m dong, n cot
{
	Matrix tich = Matrix();
	if (_n != x._m)
	{
		cout << "Khong thuc hien duoc phep tinh vi 2 MT khong cung cap" << endl;
	}
	else
	{

		tich = Matrix(_m, x._n, 0);
		for (int i = 0; i < _m; i++)
		{
			for (int j = 0; j < x._n; j++)
			{
				tich._data[i][j] = 0;
				for (int k = 0; k < _n; k++)
					tich._data[i][j] += _data[i][k] * x._data[k][j];
			}
		}
	}
	return tich;
	
}

Matrix Matrix::operator!()
{
	Matrix mtr_ngdao = Matrix();
	if (_n != _m)
	{
		cout << "Chi co ma tran vuong moi co the co ma tran nghich dao" << endl;
		return mtr_ngdao;;
	}
	if(this->determinant()==0)
	{
		cout << "Ma tran khong kha nghich" << endl;
		return mtr_ngdao;
	}
	mtr_ngdao = MatranPhuHop();
	float det = determinant();
	for (int i = 0; i < mtr_ngdao._m; i++)
	{
		for (int j = 0; j < mtr_ngdao._n; j++)
			mtr_ngdao._data[i][j] = (float)mtr_ngdao._data[i][j]/ det;
	}
	return mtr_ngdao;
}

Matrix Matrix::Chuyenvi()
{
	Matrix mtr_chvi = Matrix(_n, _m, 0);
	for (int i = 0; i < mtr_chvi._m; i++)
		for (int j = 0; j < mtr_chvi._n; j++)
			mtr_chvi._data[i][j] = _data[j][i];
	return mtr_chvi;
}

Matrix Matrix::MatranCon(int row_del, int col_del)
// Tim ma tran con cua this sau khi xoa hang row_del va cot col_del
{
	Matrix temp = Matrix();
	if (_m != _n)
		return temp;
	temp = Matrix(_n - 1, _n - 1, 0);
	for (int i = 0; i < row_del; i++) 
	{
		for (int j = 0; j < col_del; j++)
			temp._data[i][j] = _data[i][j];
		for (int j = col_del; j < temp._n; j++)
			temp._data[i][j] = _data[i][j + 1];
	}
	for (int i = row_del; i < temp._m; i++) {
		for (int j = 0; j < col_del; j++)
			temp._data[i][j] = _data[i + 1][j];
		for (int j = col_del; j < temp._n; j++)
			temp._data[i][j] = _data[i + 1][j + 1];
	}
	return temp;
}

Matrix Matrix::MatranPhuHop()
{
	Matrix temp = Matrix();
	if (_m != _n)
		return temp;
	Matrix mtr=Matrix();
	temp = Matrix(_m, _n, 0);
	for (int i = 0; i < temp._m; i++)
	{
		for (int j = 0; j < temp._n; j++)
		{
			mtr = MatranCon(i, j);
			if ((i + j) % 2 == 0)
				temp._data[i][j] = mtr.determinant();
			else
				temp._data[i][j] = -1*mtr.determinant();
		}
	}
	temp = temp.Chuyenvi();
	return temp;
}




float DetOfMatrix(float **a, int n)
{
	if (n == 1) return a[0][0];
	if (n == 2){
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

Matrix Matrix::MaTranBacThang()
{
	Matrix temp(*this);
	int key = 0;
	for (int i = 0; i < _m; i++)
	{
		for (int j = i; j < _n; j++)
		{
			if (temp._data[i][j] != 0)
			{
				for (int k = i + 1; k < _m; k++)
				{
					float t = temp._data[k][j] / temp._data[i][j];
					for (int l = j; l < _n; l++)
						temp._data[k][l] -= t * temp._data[i][l];
				}
				break;
			}
			else
			{
				for (int k = i + 1; k < _m; k++)
				{
					if (temp._data[k][j] != 0)
					{
						for (int l = 0; l < _n; l++)
							swap(temp._data[i][l], temp._data[k][l]);
						key = 3;
						break;
					}
				}
				if (key == 3) j--;
			}
		}
	}
	return temp;
}

int Matrix::rank()
{
	Matrix temp = this->MaTranBacThang();
	int rank = 0;
	for (int i = 0; i < temp._m; i++)
	for (int j = i; j < temp._n; j++)
	if (temp._data[i][j] != 0)
	{
		rank++;
		break;
	}
	return rank;
}

Matrix Matrix::operator* (float k)
{
	for (int i = 0; i < _m;i++)
	for (int j = 0; j < _n; j++)
		_data[i][j] *= k;
	return *this;
}

int Matrix::MatrixEquation(const Matrix& b)
{
	if (b._m != _m || b._n != 1) return 0;
	Matrix A;
	A._m = _m;
	A._n = _n + 1;
	A._data = new float*[_m];
	for (int i = 0; i < _m; i++)
		A._data[i] = new float[_n + 1];
	
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			A._data[i][j] = _data[i][j];
	for (int i = 0; i < _m; i++)
		A._data[i][_n] = b._data[i][0];

	int rank_A = A.rank();
	int rank_this = this->rank();
	if (rank_this < rank_A)
	{
		cout << "He vo nghiem" << endl;
		return 0;
	}
	else if (rank_A == rank_this && rank_A == _n)
	{
		cout << "He co nghiem duy nhat" << endl;
		// A*X = B => X = A^-1*B
		float det = this->determinant();
		Matrix temp;
		temp = this->MatranPhuHop();
		temp = temp* (1.0 / det);
		Matrix result(b);
		result = temp*b;
		result.output();
		return 1;
	}
	else if (rank_A == rank_this && rank_A < _n)
	{
		cout << "He phuong trinh co vo so nghiem voi bac tu do la " << _n - rank_this << endl;
		return 1;
	}
	return 0;
	
}

