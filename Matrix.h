#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Matrix
{
private:
	float **_data;
	int _m, _n;
public:
	Matrix();
	Matrix(const Matrix &x);
	Matrix(float **a, int m, int n);
	Matrix(int m, int n,float val);
	~Matrix();
	void input();
	void output();
	Matrix& operator= (const Matrix &x);
	float determinant();
	Matrix operator* (const Matrix &x);
	Matrix operator! ();
	Matrix Chuyenvi();
	Matrix MatranCon(int row_del, int col_del);
	Matrix MatranPhuHop();

	Matrix MaTranBacThang();
	int rank();

	int MatrixEquation(const Matrix& b);
	Matrix operator* (float k);
};

float DetOfMatrix(float **a, int n);

