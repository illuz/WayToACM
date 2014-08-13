/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        B.cpp
*  Create Date: 2014-08-09 09:45:03
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1e5 + 1;

int rsum[N], n, m, a, b;
vector<int> c[N];

int main() {
	scanf("%d%d", &n, &m);
	repf (j, 1, m) {
		scanf("%d%d", &a, &b);
		rsum[a]++;
		rsum[b]++;
		c[j].push_back(a);
		c[j].push_back(b);
	}
	ll sum = 0;
	repf (i, 1, m) {
		int len = c[i].size();
		repf (j, 0, len - 1) {
			sum += rsum[c[i][j]];
		}
	}
	cout << sum << endl;
	return 0;
}

