#include <iostream>
using namespace std;
/**
	Операторы и функции
	Var 17 N 1
	1. Определить, принадлежит ли точка с координатами (х, у) заштрихованной части плоскости (рис.1.17).(там функция y = x^2)
*/


void first_1(void) {
	int x, y;
	cin >> x >> y;
	if (x >= 0 && y >= x*x) {
		cout << "x:" << x << "y:" << y << "\t- belongs y = x^2" << endl;
	}
	else {
		cout << "x:" << x << "y:" << y << "\t- not belongs y = x^2" << endl;
	}
}
