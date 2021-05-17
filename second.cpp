#include <iostream>
#include <vector>

using namespace std;

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