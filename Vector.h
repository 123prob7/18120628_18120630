#pragma once
#include <iostream>
using namespace std;
class Vector
{
private:
	float *_data;
	int _n;
public:
	Vector();
	Vector(const Vector &x);
	Vector(float *v, int n);
	Vector(int n, float val);
	~Vector();
	Vector& operator= (const Vector &x);
	Vector operator+ (const Vector &x);
	Vector operator* (float k);
	void _input();
	void _output();
};

