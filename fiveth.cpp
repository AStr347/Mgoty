#include <iostream>

using namespace std;

/**
 * Одномерные массивы
 * V 17 N 1
 * 1. Даны действительные числа a1, …, an и b1, …, bn. Вычислить
 * (a1 + bn)(a2 + bn–1)…(an + b1). 
*/

void read_array(double* a, const int n){
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void fiveth_1(void){
    int n = 0;
    cin >> n;
    if(n != 0){
        double* a = new double[n];
        double* b = new double[n];
        read_array(a,n);
        read_array(b,n);

        long double result = a[0] + b[n-1];
        for (int i = 1; i < n; i++){
            result *= a[i] + b[n - i - 1];
        }
        cout << result << endl;
    }
}
