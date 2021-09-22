/**
 * Одномерные массивы
 * V 16 N 1
 * 1. Даны действительные числа a1, …, a20. 
 * Получить a20, a11, a19, a10, …, a10, a1.
*/
#include <vector>
#include <iostream>
using namespace std;

static void read_vector(vector<int>& v, const int n){
    for (int i = 0; i < n; i++){
        int _x = 0;
        cin >> _x;
        v.push_back(_x);
    }
}

/**
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * 20 11 19 10 18 9 17 8 16 7 15 6 14 5 13 4 12 3 11 2 10 1
 * 
 * 
 * 1 2 3 4 5 6 7 8 9 10 11
 * 11 2 10 1
*/

void array(void){
    int n = 0;
    /* todo: if need can be set from input */
    const int offset = 9;
    cin >> n;
    if(-1 < (n - offset - 1)){
        vector<int> in;
        read_vector(in,n);        
        vector<int> result;
        for(int i = n - 1; -1 < (i - offset); i--){
            result.push_back(in[i]);
            result.push_back(in[i - offset]);
        }
        for (int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "not need reading array because can't write how need in subject";
    }
}