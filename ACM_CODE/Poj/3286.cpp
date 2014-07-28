/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3286.cpp
*  Create Date: 2014-06-04 14:17:18
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 12;

ll b[N];
ll n, m;

void init() {
	b[0] = 1;
	for (int i = 1; i < N; i++) {
		b[i] = b[i - 1] * 10;
	}
}

ll calc(ll n, int tab) {
	ll left, m, ret = 0;
	for (int i = 1; i < 12; i++) {
		left = n / b[i] - 1;
		ret += left * b[i - 1];
		m = (n % b[i] - n % b[i - 1]) / b[i - 1];
		if (m > 0)
			ret += b[i - 1];
		else if (m == 0)
			ret += n % b[i - 1] + 1;
		if (n < b[i])
			break;
	}
	return ret;
}

int main() {
	while (cin >> m >> n && (m != -1 || n != -1)) {
		init();
		cout << calc(n, 0) - calc(m - 1, 0) << endl;
	}
	return 0;
}


