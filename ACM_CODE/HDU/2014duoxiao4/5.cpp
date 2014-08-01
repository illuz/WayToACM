/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        5.cpp
*  Create Date: 2014-07-31 12:47:07
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
typedef __int64 ll;
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

const int N = 1030;
const int MOD = 1e9+7;

ll a[N], d1[N][N<<1+1], d2[N][N];
int t, n;

void read() {
	scanf("%d", &n);
	repf (i, 1, n) {
		scanf("%I64d", &a[i]);
	}
}

void dp1() {
	memset(d1, 0, sizeof(d1));
	d1[1][a[1]]++;
	repf (i, 1, n - 1) {
		repf (j, 0, N<<1) {
			if (d1[i][j]) {
				d1[i + 1][j^a[i + 1]] += d1[i][j];
				d1[i + 1][j^a[i + 1]] %= MOD;
			}
		}
		d1[i + 1][a[i + 1]]++;		// choose a[i] only
		d1[i + 1][a[i + 1]] %= MOD; }
}

void dp2() {
	memset(d2, 0, sizeof(d2));
	d2[n][a[n]]++;
	repd (i, n, 2) {
		repf (j, 0, N - 1) {
			d2[i - 1][j] = d2[i][j];
		}
		repf (j, 0, N - 1) {
			if (d2[i][j]) {
				d2[i - 1][j&a[i - 1]] += d2[i][j];
				d2[i - 1][j&a[i - 1]] %= MOD;
			}
		}
		d2[i - 1][a[i - 1]]++;
		d2[i - 1][a[i - 1]] %= MOD;
	}
}

void solve() {
	ll ans = 0;
	repf (i, 0, N - 1) {
		repf (j, 1, n - 1) {
			ans = (ans + (d1[j][i] * d2[j + 1][i])%MOD) % MOD;
		}
	}
	printf("%I64d\n", ans);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		read();
		dp1();
		dp2();
		solve();
	}
	return 0;
}

