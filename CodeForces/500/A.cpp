/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-12-30 23:05:16
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 30100;

int n, t;
int a[N];

int main() {
	cin >> n >> t;
	for (int i = 1; i < n; i++)
		cin >> a[i];
	int cur = 1;
	while (1) {
		if (cur == t) {
			cout << "YES" << endl;
			break;
		}
		if (cur >= n) {
			cout << "NO" << endl;
			break;
		}
		cur = cur + a[cur];
	}
	return 0;
}

