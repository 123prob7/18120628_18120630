#pragma once
#include <iostream>
using namespace std;
class Vector
{
private:
	float *_v;
	int _n;
public:
	Vector();
	Vector(const Vector &x);
	Vector(float *v, int n);
	~Vector();
	Vector& operator= (const Vector &x);
	Vector operator+ (const Vector &x);
	Vector operator* (int k);
	void _input();
	void _output();
};

