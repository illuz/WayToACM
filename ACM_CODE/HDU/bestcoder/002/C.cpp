/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-07-27 20:20:37
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#include <cmath>
#include <cstdlib>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <sstream>
#include <utility>
#include <cctype>
/****************************/
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() puts("")
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi first
#define sd second
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 1010;

int t, n, L, vis[N];
PII p[N];
vector<int> g[N];
queue<PII> q;

void link(int a, int b) {
	if (sqr(p[a].fi - p[b].fi) + sqr(p[a].sd - p[b].sd) <= L * L) {
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

int main() {
	RI(t);
	while (t--) {
		RII(n, L);
		int cnt = 2;
		rep (i, n + 2) {
			g[i].clear();
		}
		RII(p[0].fi, p[0].sd);
		RII(p[1].fi, p[1].sd);
		link(0, 1);
		rep (i, n) {
			RII(p[cnt].fi, p[cnt].sd);
			rep (i, cnt)
				link(cnt, i);
			cnt++;
		}

		while (!q.empty())
			q.pop();
		q.push(MP(0,0));
		clr(vis);
		vis[0] = 1;
		int ans = 0;
		while (!q.empty()) {
			PII u = q.front();
			q.pop();
			rep (i, g[u.fi].size()) {
				if (g[u.fi][i] == 1) {
					ans = u.sd;
					break;
				}
				if (!vis[g[u.fi][i]]) {
					vis[g[u.fi][i]] = 1;
					q.push(MP(g[u.fi][i], u.sd+1));
				}
			}
			if (ans) break;
		}
		if (ans == 0) puts("impossible");
		else printf("%d\n", ans);
	}
	return 0;
}
