/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        8.cpp
*  Create Date: 2014-09-20 15:29:48
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

// LCA template from kuangbin GG.
const int MAXN = 10010;
const int DEG = 20;

struct Edge {
	int to, next;
} edge[MAXN*2];
int head[MAXN],tot;

void addedge(int u,int v) {
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

int fa[MAXN][DEG];//fa[i][j]表示结点i的第2^j个祖先
int deg[MAXN];//深度数组

void BFS(int root)
{
	queue<int>que;
	deg[root] = 0;
	fa[root][0] = root;
	que.push(root);
	while(!que.empty()) {
		int tmp = que.front();
		que.pop();
		for(int i = 1;i < DEG;i++)
			fa[tmp][i] = fa[fa[tmp][i-1]][i-1];
		for(int i = head[tmp]; i != -1;i = edge[i].next) {
			int v = edge[i].to;
			if(v == fa[tmp][0])continue;
			deg[v] = deg[tmp] + 1;
			fa[v][0] = tmp;
			que.push(v);
		}
	}
}

int LCA(int u,int v) {
	if(deg[u] > deg[v])swap(u,v);
	int hu = deg[u], hv = deg[v];
	int tu = u, tv = v;
	for(int det = hv-hu, i = 0; det ;det>>=1, i++)
		if(det&1)
			tv = fa[tv][i];
	if(tu == tv)return tu;
	for(int i = DEG-1; i >= 0; i--) {
		if(fa[tu][i] == fa[tv][i])
			continue;
		tu = fa[tu][i];
		tv = fa[tv][i];
	}
	return fa[tu][0];
}



bool flag[MAXN];
int n, m, x, y, t;
bool vis[MAXN];
vector<int> vv[MAXN];
queue<int> qq;

void init() {
	tot = 0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	repf (i, 0, n)
		vv[i].clear();
}

void bfs() {
	while (!qq.empty())
		qq.pop();
	qq.push(1);
	vis[1] = 1;
	while (!qq.empty()) {
		int u = qq.front();
		qq.pop();
		int sz = vv[u].size();
		repf (i, 0, sz - 1) {
			int v = vv[u][i];
			if (!vis[v]) {
				vis[v] = 1;
				addedge(u, v);
				qq.push(v);
			}
		}
	}
}

int main() {
	while (~scanf("%d%d", &n, &m) && (n || m)) {
//		repf (i, 1, n - 1) {
//			scanf("%d%d", &x, &y);
//			vv[x].push_back(y);
//			vv[y].push_back(x);
//		}
		int u,v;
		init();
		memset(flag,false,sizeof(flag));
		for(int i = 1;i < n;i++) {
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
			flag[v] = true;
		}
		int root;
		for(int i = 1;i <= n;i++)
			if(!flag[i])
			{
				root = i;
				break;
			}
		cout << "!!" << root << endl;
		BFS(root);
		repf (i, 0, m - 1) {
			scanf("%d%d",&u,&v);
			printf("%d\n",LCA(u, v));
		}
		// bfs();
	}
	return 0;
}
