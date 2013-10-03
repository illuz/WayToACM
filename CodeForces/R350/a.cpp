/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        a.cpp
*  Create Date: 2013-10-01 23:38:47
*  Descripton:  a 
*/

#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
	int n, m, Mina = 100, Maxa = 0, Minb = 100, t;
	cin >> n >> m;
	rep(i, n) {
		cin >> t;
		Mina = min(Mina, t);
		Maxa = max(Maxa, t);
	}
	rep(i, m) {
		cin >> t;
		Minb = min(Minb, t);
	}
	if (Mina * 2 >= Minb || Minb <= Maxa) {
		puts("-1");
		return 0;
	}
	cout << max(Mina * 2, Maxa) << endl;
	return 0;
}
