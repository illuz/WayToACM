/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1.cpp
*  Create Date: 2014-08-21 13:08:08
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

const int N = 100;

int G[N][N], pj[N], pb[N];
vector<int> solve[N], rec[N];
int t, n, m;
ll sum, stat, need[N];
map<ll, ll> mp, mp2;

void dfs(int u) {
	if (stat & (1<<u)) return;
	stat |= (1<<u);

	repf (i, 0, m - 1) {
		if (G[u][i]) {
			dfs(i);
		}
	}
}

int main() {
	RI(t);
	repf (cas, 1, t) {
		RII(n, m);
		repf (i, 0, n - 1)
			RI(pj[i]);
		repf (i, 0, m - 1)
			RI(pb[i]);
		int num, rd;
		repf (i, 0, n - 1) {
			rec[i].clear();
			solve[i].clear();
			RI(num);
			repf (j, 0, num - 1) {
				RI(rd);
				solve[i].push_back(rd);
			}
		}
		repf (i, 0, m - 1)
			repf (j, 0, m - 1) {
				RI(G[i][j]);
			}

		repf (i, 0, n - 1) {
			stat = 0;
			int sz = solve[i].size();
			repf (j, 0, sz - 1) {
				dfs(solve[i][j]);
			}
			need[i] = stat;
			repf (j, 0, i - 1) {
				if ((need[i] & need[j]) == need[j]) {
					rec[i].push_back(j);
				}
			}
		}

		ll ans = -INF;
		mp.clear();
		mp2.clear();
		for (int i = (1<<n) - 1; i >= 0; i--) {
			sum = 0;
			ll st = 0;
			repf (j, 0, n - 1) {
				if ((i&(1<<j))) {
					sum += pj[j];
					st |= need[j];
					int sz = rec[j].size();
					repf (k, 0, sz - 1) {
						if (st&(1<<rec[j][k]) == 0) {
							sum += pj[rec[j][k]];
						}
					}
				}
			}
			if (sum <= ans) continue;
			if (mp.find(st) != mp.end()) {
				sum -= mp[st];
			} else {
				ll tmp = 0;
				repf (j, 0, m - 1) {
					if (st&(1<<j)) {
						sum -= pb[j];
						tmp += pb[j];
					}
					if (sum <= ans) break;
				}
				mp[st] = tmp;
			if (sum <= ans) continue;
			}
			ans = max(ans, sum);
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}

