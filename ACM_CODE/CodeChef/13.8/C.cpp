 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          C.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-19 01:28:47
 *   Descripton:    CC 13.8 C 
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
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 10010;
int n, m, cnt;
int a[MAXN], b[MAXN];
bool vis[MAXN];
vector<int> c[MAXN];

void dfs(int d) {
	if (d >= m + 2) {
		cnt++;
		return;
	}
	FI(i, c[d])
		if (!vis[*i]) {
			vis[*i] = true;
			dfs(d + 1);
			vis[*i] = false;
		}
}

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		repu(i, 2, m + 2) scanf("%d", &a[i]);
		a[m + 3] = a[m + 4] = 0;
		repu(i, 2, m + 2) scanf("%d", &b[i]);
		b[m + 3] = b[m + 4] = 0;
		repu(i, 2, m + 2) {
			c[i].clear();
			repf(j, 1, m) {
				if (j != a[i] && j != b[i])
					c[i].push_back(j);
			}
		}
		cnt = 0;
		dfs(2);
		printf("%d\n", cnt);
	}
	return 0;
}

