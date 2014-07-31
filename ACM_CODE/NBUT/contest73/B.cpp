/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-07-09 16:29:29
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
using namespace std;

const int N = 0;
int t;
long long n;

int main() {
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		if (n <= 2) cout << n << endl;
		else if (n & 1) cout << n * (n - 1) * (n - 2) << endl;
		else if (n % 3) cout << n * (n - 1) * (n - 3) << endl;
		else cout << (n - 1) * (n - 2) * (n - 3) << endl;
	}
	return 0;
}

