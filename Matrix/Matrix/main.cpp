#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

	Matrix<2, 3> A{ {1,2,3},{2,3,1} }, B({ {-1,1,4},{0,0,3} });
	Matrix<3, 1> x(3.0), y({ { 0 }, { 1 }, { 0 } });
	Matrix<2, 1> z, res{ {48},{45} };
	z.zero();
	Matrix<2, 3> M;
	M.eye();

	std::cout << A;
	std::cout << B;
	std::cout << x;
	std::cout << y;
	std::cout << z;
	std::cout << res;
	std::cout << M;

	std::cout << "TU sam!\n";
	A += B;
	std::cout << A;
	Matrix<2, 3> C = A + B;
	std::cout << C;
	Matrix<2, 3> D = A - B;
	std::cout << D;

	Matrix<2, 1> vv = res * 10.0;
	std::cout << vv;
	Matrix<2, 1> vv1 = 10.0 * res;
	std::cout << vv1;

	z = (2 * A - M + B * 3)*(x - 3 * y);
	z -= res;
	if (z) cout << "o.k.\n";
	else  cout << "pogresno!\n";




}