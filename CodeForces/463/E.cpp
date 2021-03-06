/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        E.cpp
*  Create Date: 2014-08-30 19:20:17
*  Descripton:  brute force, gcd
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1e5 + 10;

vector<int> mp[N];
int n, q, v[N], fa[N], x, y;

void dfs(int x, int f) {
	fa[x] = f;
	int sz = mp[x].size();
	repf (i, 0, sz - 1) {
		if (mp[x][i] != f) {
			dfs(mp[x][i], x);
		}
	}
}

int main() {
	scanf("%d%d", &n, &q);
	repf (i, 1, n) {
		scanf("%d", &v[i]);
	}
	repf (i, 1, n - 1) {
		scanf("%d%d", &x, &y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	dfs(1, 0);
	repf (i, 1, q) {
		scanf("%d", &x);
		if (x == 1) {
			scanf("%d", &y);
			int i;
			for (i = fa[y]; i; i = fa[i])
				if (__gcd(v[i], v[y]) > 1)
					break;
			if (!i)
				printf("-1\n");
			else
				printf("%d\n", i);
		} else {
			scanf("%d %d", &x, &y);
			v[x] = y;
		}
	}
	return 0;
}

