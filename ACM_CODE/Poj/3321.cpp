/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3321.cpp
*  Create Date: 2014-10-06 21:10:51
*  Descripton:  dfs + BIT
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1e5 + 10;

vector<vector<int> > g(N);
int tin[N], tout[N], step;
int app[N];
int n, q, a, b;
char op[3];
int tree[N];

void dfs(int now, int fa) {
	tin[now] = ++step;
	repf (i, 0, (int)g[now].size() - 1)
		if (g[now][i] != fa)
			dfs(g[now][i], now);
	tout[now] = step;
}

void update(int pos, int val) {
	for (; pos <= n; pos += (pos&-pos))
		tree[pos] += val;
}
int sum(int pos) {
	int ret = 0;
	for (; pos; pos &= (pos - 1))
		ret += tree[pos];
	return ret;
}

int main() {
	scanf("%d", &n);
	app[1] = true;
	repf (i, 2, n) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		app[i] = true;
	}

	step = 0;
	dfs(1, 0);

	repf (i, 1, n)
		update(i, 1);

	scanf("%d", &q);
	repf (i, 0, q - 1) {
		scanf("%s %d", op, &a);
		if (op[0] == 'C') {
			update(tin[a], app[a] ? -1 : 1);
			app[a] = !app[a];
		} else {
			printf("%d\n", sum(tout[a]) - sum(tin[a] - 1));
		}
	}
	return 0;
}

