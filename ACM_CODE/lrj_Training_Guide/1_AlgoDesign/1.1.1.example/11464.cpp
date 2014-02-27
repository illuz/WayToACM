/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11464.cpp
*  Create Date: 2014-02-09 23:17:29
*  Descripton:  uva 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
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
/****************************/
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() printf("")
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define clr(a) memset(a,0,sizeof(a))
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 20;

int t, n;
int mat[N][N];
int ans;

int calc(int stat) {
	stat = stat<<1;
	// prestate, preprestate
	int pstat = stat, ppstat = 0, ret = 0;
	// compute the first line
	repf(i, 1, n) {
		int t = (stat>>i)&1;
		if (t == mat[1][i]) continue;
		if (t) ret++;
		else return INF;
	}
	// get the other line
	repf(i, 2, n) {
		stat = 0;
		repf(j, 1, n) {
			int t = (ppstat>>j) + (pstat>>(j+1)) + (pstat>>(j-1));
			t &= 1;
			stat |= (t<<j);
			// judge and compute
			if (t == mat[i][j]) continue;
			if (t) {
				ret++;
				if (ret >= ans) return INF;
			}
			else return INF;
		}
		ppstat = pstat;
		pstat = stat;
	}
	return ret;
}

int main() {
	RI(t);
	rep(cas, t) {
		RI(n);
		rep(i, n) rep(j, n) {
			RI(mat[i + 1][j + 1]);
		}
		ans = INF;
		rep(i, (1<<n))
			ans = min(ans, calc(i));
		if (ans == INF) ans = -1;
		printf("Case %d: %d\n", cas + 1, ans);
	}
	return 0;
}

