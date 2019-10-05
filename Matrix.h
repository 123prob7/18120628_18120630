#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Matrix
{
private:
	float **_a;
	int _m, _n;
public:
	Matrix();
	Matrix(const Matrix &x);
	Matrix(float **a, int m, int n);
	~Matrix();
	void _input();
	void _output();
	Matrix& operator= (const Matrix &x);
	float _determinant();
	Matrix operator* (const Matrix &x);
	
};

float DetOfMatrix(float **a, int n);

