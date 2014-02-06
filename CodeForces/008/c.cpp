/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        c.cpp
*  Create Date: 2014-02-02 16:57:07
*  Descripton:   
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
const double PI=acos(-1.0);
const int dx[]= {0,-1,0,1};
const int dy[]= {1,0,-1,0};
const int fx[]= {-1,-1,-1,0,0,1,1,1};
const int fy[]= {-1,0,1,-1,1,-1,0,1};
/***************************************/
void openfile()
{
	    freopen("data.in","rb",stdin);
		    freopen("data.out","wb",stdout);
}
/****** TEMPLATE ENDS *******/

const int N = 1<<24 + 1;

int x[25], y[25];
int ox, oy, n;
int next, newdist;
int dist[25][25];
int dir[25];
int best[N];
int path[N];

int main() {
	RII(ox, oy);
	RI(n);
	// the direct distance and distance
	rep(i, n) {
		RII(x[i], y[i]);
		dir[i] = sqr(x[i] - ox) + sqr(y[i] - oy);
	}
	rep(i, n) rep(j, n)
		dist[i][j] = dist[j][i] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
	// dp
	rep(mask, (1<<n)) if (mask == 0 || best[mask] > 0) {
		rep(i, n) if (!(mask&(1<<i))) {
			repf(j, i, n-1) if (!(mask&(1<<j))) {	// include i
				next = mask|(1<<i)|(1<<j);
				newdist = best[mask] + dir[i] + dir[j] + dist[i][j];
				if (!best[next] || best[next] > newdist) {
					best[next] = newdist;
					path[next] = mask;
				}
			}
			break;		// because just find the first 0
		}
	}
	// output path
	printf("%d\n0", best[(1<<n) - 1]);
	for (int i = (1<<n) - 1; i; i = path[i]) {
		rep(j, n)
			if ((i&(1<<j)) != (path[i]&(1<<j)))
				printf(" %d", j + 1);
		printf(" 0");
	}
	return 0;
}

