/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        01_test.cpp
*  Create Date: 2014-09-30 14:51:49
*  Descripton:  test the program
*/

#include <bits/stdc++.h>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1e5 + 10;

int a[N], n, q, t;

int F(int l, int r) {
	int g = a[l];
	repf (i, l + 1, r)
		g = __gcd(g, a[i]);
	return g;
}

pair<int,int> get_RANK(int l,int r) {
	map<int,int>mp;
	int k1 = 1, k2 = 1;
	for(int i = 1;i <= N;i++)
		for(int j = i;j <= N;j++) {
			if(i == l && j == r)continue;
			if(F(i,j) < F(l,r)) {
				if(mp.find(F(i,j)) != mp.end())continue;
				k1++;
				mp[F(i,j)] = 1;
			}
			else if(F(i,j) == F(l,r)) {
				if(i < l || (i == l && j < r))k2++;
			}
		}
	return make_pair(k1,k2);
}

int main() {
	// ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> q;
		repf (i, 1, n)
			cin >> a[i];
	}
	return 0;
}

