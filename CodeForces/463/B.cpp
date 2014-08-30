/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        B.cpp
*  Create Date: 2014-08-30 15:57:02
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1e5 + 10;

ll n, h[N];
ll energy, cast;

int main() {
	while (cin >> n) {
		energy = 0, cast = 0;
		repf (i, 1, n) {
			cin >> h[i];
		}
		repf (i, 0, n - 1) {
			energy += h[i] - h[i + 1];
			if (energy < 0) {
				cast += -energy;
				energy = 0;
			}
		}
		cout << cast << endl;
	}
	return 0;
}

