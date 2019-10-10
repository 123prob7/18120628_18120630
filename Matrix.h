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
	void _input();
	void _output();
	Matrix& operator= (const Matrix &x);
	float _determinant();
	Matrix operator* (const Matrix &x);
	Matrix operator! ();
	Matrix Chuyenvi();
	Matrix MatranCon(int row_del, int col_del);
	Matrix MatranPhuHop();

	
};

float DetOfMatrix(float **a, int n);

