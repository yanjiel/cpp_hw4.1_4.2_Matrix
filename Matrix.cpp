//compile with ISO C++20 Standard /std::c++20

#include "Matrix.h"
#include <iostream>
#include <chrono>
using namespace mpcs51044;
using namespace std;

int main()
{
	auto start = chrono::system_clock::now();
	Matrix<3, 3> m = {
			{ 1, 2, 3, },
			{ 4, 5, 6, },
			{ 7, 8, 9, }
	};

	//Matrix<3, 3> m2 = {
	//		{ 1, 2, 3, },
	//		{ 4, 5, 6, },
	//		{ 7, 8, 9, }
	//};

	//Matrix<3, 2> m3 = {
	//	{ 1, 2, },
	//	{ 1, 2, },
	//	{ 1, 2, }
	//};

	//Matrix<3, 3> m5 = m + m2;
	//cout << m5;

	//Matrix <3, 2> m4 = m * m3;
	//cout << m4;

	//m += m2;
	//cout << m;

	static double total;
	for (int i = 0; i < 100'000'000; i++) {
		m(1, 1) = i;
		total += m.determinant();
	}
	cout << chrono::duration<double>(chrono::system_clock::now() - start).count() << " seconds\n";
}