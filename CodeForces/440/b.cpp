/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-06-04 11:03:34
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
using namespace std;

const int N = 5e4 + 10;

long long n, a[N], sum, avg, ans, tmp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	avg = sum / n;
	for (int i = 0; i < n; i++) {
		tmp += a[i] - avg;
		ans += tmp > 0 ? tmp : -tmp;
	}
	cout << ans << endl;
	return 0;
}

