#include "Vector.h"
#include "Matrix.h"
#include <conio.h>

int main()
{
	/*Vector a, b;
	a._input();
	b._input();
	Vector c;
	c = a + b;
	c._output();
	*/
	Matrix q;
	q._input();
	cout << q._determinant();
	_getch();
	return 0;
}