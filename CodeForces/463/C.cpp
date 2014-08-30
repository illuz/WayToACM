/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        C.cpp
*  Create Date: 2014-08-30 16:26:14
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 2010;

int n;
ll v;
ll x[N*2], y[N*2], mp[N][N];
pair<int, int> A, B;
ll am, bm;

int main() {
	scanf("%d", &n);
	A.first = 1;
	A.second = 2;
	B.first = 1;
	B.second = 1;
	repf (i, 1, n) repf (j, 1, n) {
		scanf("%lld", &v);
		x[i + j] += v;
		y[i - j + N] += v;
		mp[i][j] = v;
	}
	repf (i, 1, n) repf (j, 1, n) {
		v = x[i + j] + y[i - j + N] - mp[i][j];
		if ((i + j) % 2) {
			if (am < v) {
				am = v;
				A.first = i;
				A.second = j;
			}
		} else {
			if (bm < v) {
				bm = v;
				B.first = i;
				B.second = j;
			}
		}
	}
	cout << am + bm << endl;
	cout << A.first << ' ' << A.second << ' ';
	cout << B.first << ' ' << B.second << endl;
	return 0;
}

