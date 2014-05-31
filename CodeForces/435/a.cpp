/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-05-30 23:32:27
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int n, m, a[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0, cnt = 0;
	while (i < n) {
		int t = m;
		while (t >= a[i] && i < n) {
			t -= a[i];
			i++;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}

