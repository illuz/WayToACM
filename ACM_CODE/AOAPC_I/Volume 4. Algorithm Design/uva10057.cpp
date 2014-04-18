 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          uva10057.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-25 11:30:04
 *   Descripton:    UVA 10057 A mid-summer night's dream, simulation 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 1000000;
int n, num[MAXN], n1, n2;

int main() {
	while (scanf("%d", &n) != EOF) {
		rep(i, n) {
			scanf("%d", &num[i]);
		}
		sort (num, num + n);
		int k = (n - 1) / 2;
		n1 = 0; n2 = 1;
		if (n % 2) {
			for (int i = k; i >= 0 && num[k] == num[i]; i--)
				n1++;
			for (int i = k + 1; i < n && num[k] == num[i]; i++)
				n1++;
		}
		else {
			for (int i = k; i >= 0 && num[k] == num[i]; i--)
				n1++;
			for (int i = k + 1; i < n && num[k + 1] == num[i]; i++)
				n1++;
			n2 = num[k + 1] - num[k] + 1;
		}
		printf("%d %d %d\n", num[k], n1, n2);
	}
	return 0;
}

