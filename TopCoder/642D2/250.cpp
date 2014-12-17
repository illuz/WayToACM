/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        250.cpp
*  Create Date: 2014-12-17 10:11:32
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 0;

class ForgetfulAddition {
private:
	int calc(string a) {
		int ret = 0;
		int len = a.length();
		for (int i = 0; i < len; i++)
			ret = ret * 10 + a[i] - '0';
		return ret;
	}
public:
	int minNumber(string ex) {
		int len = ex.length();
		int ret = 0x7fffffff;
		for (int i = 1; i < len; i++) {
			ret = min(calc(ex.substr(0, i)) + calc(ex.substr(i)), ret);
		}
		return ret;
	}
};


int main() {
	ForgetfulAddition s;
	string st;
	while (cin >> st)
		cout << s.minNumber(st) << endl;
	return 0;
}

