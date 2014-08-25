/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        4972.cpp
*  Create Date: 2014-08-23 20:18:07
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1000010;

int arr[N], t, n;

int solve() {
	int cnt = 1;
	repf (i, 2, n) {
		if (arr[i - 1] == 1 && arr[i] == 2)
			cnt++;
		if (arr[i - 1] == 2 && arr[i] == 1)
			cnt++;
		if (arr[i - 1] - arr[i] > 3 || arr[i] - arr[i - 1] > 3)
			return 0;
		if (arr[i] == arr[i - 1] && arr[i] != 1)
			return 0;
	}
	if (arr[n])
		return cnt * 2;
	else
		return cnt;
}

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d", &n);
		repf (i, 1, n)
			scanf("%d", &arr[i]);
		printf("Case #%d: %d\n", cas, solve());
	}
	return 0;
}

