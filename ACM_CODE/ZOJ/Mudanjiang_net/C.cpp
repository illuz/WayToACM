/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-09-07 13:59:56
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

const int N = 1e5 + 10;

int n, m, k, l, rec[N];
bool vis[N];
bool cgq[N];

vector<int> v[N];

int dfs2(int x) {
	vis[x] = 1;
	int ret = 1;
	int sz = v[x].size();
	repf (i, 0, sz - 1) if (!vis[v[x][i]]) {
		ret += dfs2(v[x][i]);
	}
	return ret;
}

void dfs(int x) {
	int sz = v[x].size();
	if (cgq[x] == true) {
		cgq[x] = false;
		vis[x] = true;
		return;
	}
	repf (i, 0, sz - 1) {
		if (!vis[v[x][i]]) {
			vis[v[x][i]] = true;
			dfs(v[x][i]);
		}
	}
}

bool solve() {
	clr(vis);
	cgq[rec[1]] = false;
	repf (i, 1, l) {
		if (cgq[rec[i]] == true)
			return false;
		dfs(rec[i]);
	}
	return true;
}

int main() {
	int t, rd, x, y;
	RI(t);
	while (t--) {
		clr(vis);
		clr(cgq);
		RII(n, m);
		RI(k);
		repf (i, 0, n) {
			v[i].clear();
		}
		repf (i, 1, k) {
			RI(rd);
			cgq[rd] = 1;
		}
		repf (i, 0, m - 1) {
			RII(x, y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		scanf("%d", &l);
		repf (i, 1, l) {
			RI(rec[i]);
		}
		int tot = dfs2(1);
		if (l != k || tot != n) {
			printf("No\n");
		} else {
			if (solve()) {
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
	return 0;
}

