/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2155.cpp
*  Create Date: 2014-03-28 15:48:20
*  Descripton:  union find 
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

const int N = 1300000;

int f[N];
int vis[N];
int n, m, a, b, cnt, mmax;
char o[2];

int find(int x)
{
	if (x == f[x])
		return x;
	else return f[x] = find(f[x]);
}

int main()
{
	int cas = 1;
	while (RII(n, m) && (n || m)) {
		// init
		clr(vis);
		rep (i, n) f[i] = f[i + n] = i + n;

		// uf
		mmax = m * 2;
		rep (i, m) {
			scanf("%s", o);
			if (o[0] == 'M') {
				RII(a, b);
				a = find(a);
				b = find(b);
				f[a] = b;
			}
			else {
				RI(a);
				f[mmax] = mmax;
				f[a] = mmax++;
			}
		}
		cnt = 0;
		rep (i, n) {
			a = find(i);
			if (!vis[a]) {
				vis[a] = 1;
				cnt++;
			}
		}
		printf("Case #%d: %d\n", cas++, cnt); 
	}
	return 0;
}

