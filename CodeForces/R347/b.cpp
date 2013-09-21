/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2013-09-20 23:43:46
*  Descripton:  b 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
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

const int MAXN = 100100;
int a[MAXN], n, cnt;
int rec[MAXN], r;

int main() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a[i]);
		if (a[i] == i)
			cnt++;
		else
			rec[r++] = i;
	}
	int cg = r > 0 ? 1 : 0;
	rep(i, r)
		if (a[a[rec[i]]] == rec[i]) {
			cg = 2;
			break;
		}
	printf("%d\n", cnt + cg);
	return 0;
}


