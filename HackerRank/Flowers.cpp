/*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          Flowers.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-09-06 15:46:01
 *   Descripton:    flowers 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 110;
int a[MAXN];
int n, k;
LL sum = 0;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n, cmp);
	rep(i, n) sum += a[i] * (i / k + 1);
	printf("%lld\n", sum);
	return 0;
}

