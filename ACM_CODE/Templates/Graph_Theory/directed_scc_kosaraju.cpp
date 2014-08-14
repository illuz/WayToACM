/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        directed_scc_kosaraju.cpp
*  Create Date: 2014-08-13 14:48:03
*  Descripton:  kosaraju algorithm
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 0;

vector<int> G[N], G2[N];
vector<int> S;
int vis[N], sccno[N], scccnt;

void dfs1(int u) {
	if (vis[u])
		return;
	vis[u] = 1;
	int sz = G[u].size();
	repf (i, 0, sz - 1) {
		dfs1(G[u][i]);
	}
	S.push_back(u);
}

void dfs2(int u) {
	if (sccno[u])
		return;
	sccno[u] = scccnt;
	int sz = G2[u].size();
	repf (i, 0, sz - 1) {
		dfs2(G[u][i]);
	}
}

void find_scc(int n) {
	scccnt = 0;
	S.clear();
	memset(sccno, 0, sizeof(sccno));
	memset(vis, 0, sizeof(vis));
	repf (i, 0, n - 1)
		dfs1(i);
	for (int i = n - 1; i >= 0; i--) {
		if (!sccno[S[i]]) {
			scccnt++;
			dfs2(S[i]);
		}
	}
}

int main() {

	return 0;
}

