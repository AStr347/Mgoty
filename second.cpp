#include <iostream>
#include <vector>
using namespace std;

/**
	Одномерные массивы
	Var 17 N 5
	5. Даны целые числа a1, …, an. Получить новую последовательность
	из n чисел, заменяя ai нулями, если |ai| не равно max(a1, …, an), и заменяя ai единицей в противном случае (i = 1, …, n).
*/

void second_5() {
	vector<int> inv;
	int n;
	int max = INT_MIN;
	cin >> n;
	/* read data and find max */
	for (int i = 0; i < n; i++) {
		int __x;
		cin >> __x;
		if (__x > max) {
			max = __x;
		}
		inv.push_back(__x);
	}

	/* create new vector, fill and print */
	vector<int> outv;
	for (auto& i : inv) {
		int in = abs(i) == max ? 1 : 0;
		outv.push_back(in);
		cout << in;
	}
	cout << endl;
}