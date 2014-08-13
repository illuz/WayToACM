/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        5.cpp
*  Create Date: 2014-08-07 12:18:38
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

const int N = 110;

int mp[N][N];
int t, n, m;
ll a1, a2;

ll f(int x, int y) {
	int ret = 1;
	if (mp[x - 1][y] == 0) ret <<= 1;
	if (mp[x + 1][y] == 0) ret <<= 1;
	if (mp[x][y - 1] == 0) ret <<= 1;
	if (mp[x][y + 1] == 0) ret <<= 1;
	return ret;
}

int main() {
	RI(t);
	while (t--) {
		RII(n, m);
		a1 = a2 = 0;
		memset(mp, -1, sizeof(mp));
		bool xx = 0;
		repf (i, 1, m) {
			mp[1][i] = xx;
			xx = !xx;
		}
		repf (i, 2, n) repf (j, 1, m) {
			mp[i][j] = !mp[i - 1][j];
		}
		repf (i, 1, n) repf (j, 1, m) {
			if (mp[i][j])
				a1 += f(i, j);
		}

		memset(mp, -1, sizeof(mp));
		xx = 1;
		repf (i, 1, m) {
			mp[1][i] = xx;
			xx = !xx;
		}
		repf (i, 2, n) repf (j, 1, m) {
			mp[i][j] = !mp[i - 1][j];
		}
		repf (i, 1, n) repf (j, 1, m) {
			if (mp[i][j])
				a2 += f(i, j);
		}
		cout << max(a1, a2) << endl;
	}
	return 0;
}

