/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-11-06 19:03:34
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1e5+10;

int a, m;

int main() {
	cin >> a >> m;
	bool flag = 0;
	for (int i = 1; i <= m; ) {
		if (i * a % m == 0) {
			flag = true;
			break;
		}
		i *= 2;
	}
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}

