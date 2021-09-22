/**
 * V 16 N 1
 * 1. Даны натуральное число n, символы s1, …, sn. Выяснить, имеются ли в последовательности s1, …, sn 
 * такие члены последовательности si, si+1, что si — это запятая, а si+1 — тире. 
*/

#include <string>
#include <iostream>

using namespace std;

void strings(void){
    string s;
    getline(cin, s);
    size_t res_i = s.find(",-");
    bool result = res_i != string::npos;
    cout << "\",-\" " << (result? "found" : "not found") << ", index = " << (int64_t)res_i << endl;
}