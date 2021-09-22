#include <iostream>
#include <vector>
using namespace std;

/**
 * Одномерные массивы
 * V 17 N 1
 * 1. Даны действительные числа a1, …, an и b1, …, bn. Вычислить
 * (a1 + bn)(a2 + bn–1)…(an + b1). 
*/

static void read_vector(vector<int>& v, const int n){
    for (int i = 0; i < n; i++){
        int _x = 0;
        cin >> _x;
        v.push_back(_x);
    }
}

void fiveth_1(void){
    int n = 0;
    cin >> n;
    if(n != 0){
        vector<int> a;
        vector<int> b;
        read_vector(a,n);
        read_vector(b,n);

        long double result = a[0] + b[n-1];
        for (int i = 1; i < n; i++){
            result *= a[i] + b[n - i - 1];
        }
        cout << result << endl;
    }
}
