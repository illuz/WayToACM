/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        d.cpp
*  Create Date: 2014-01-13 14:26:11
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
#define PI(x) printf("%d",&x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() printf("")
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define clr(a, b) memset(a,(b),sizeof(a))
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

const int N = 5010;
struct Node {
	int h, w;
	int num;
} p[N];
int n, w, h, cnt, rw, rh;
int dp[N], path[N];

bool cmp(const Node &a, const Node &b) {
	return a.w < b.w || (a.w == b.w && a.h < b.h);
}

void pp(int x) {
	if (x == -1) return;
	pp(path[x]);
	printf("%d ", p[x].num);
}

int main() {
	RI(n);
	RII(w, h);
	repf(i, 1, n) {
		RII(rw, rh);
		if (rw > w && rh > h) {
			p[cnt].w = rw;
			p[cnt].h = rh;
			p[cnt++].num = i;
		}
	}
	rep(i, n) dp[i] = 1;
	clr(path, -1);
	sort(p, p + cnt, cmp);
	int ans = 0, rec = -1;
	rep(i, cnt) { repd(j, i, 0)
		if (p[i].w > p[j].w && p[i].h > p[j].h)
			if (dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				path[i] = j;
			}
		if (ans < dp[i]) {
			ans = dp[i];
			rec = i;
		}
	}
	PIN(ans);
	pp(rec);
	return 0;
}

