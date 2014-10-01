/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-09-29 11:10:46
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1e6 + 10;
int n;
bool d[N];

bool f(int x) {
	repf (i, 2, x) {
		if (d[i]) continue;
		for (int j = i + i; j < x; j += i) {
			d[j] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> n) {
		f(n);
		repf (i, 2, n / 2 + 1) {
			if (d[i] && d[n - i]) {
				cout << i << ' ' << n - i << endl;
				break;
			}
		}
	}
	return 0;
}

