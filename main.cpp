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
	c._output();*/
	Matrix p;
	p._input();
	p._output();
	//Matrix q;
	//q._input();
	//q._output();
	
	//cout << q._determinant();
	/*Matrix t=p.Chuyenvi();
	t = p * q;
	t._output();*/

	Matrix k = !p;
	k._output();
	
	_getch();
	return 0;
}