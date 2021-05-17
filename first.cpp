#include <iostream>
using namespace std;

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
